################################################################################
# Copyright (C) 2022 by Andreas Zenk
#
# Permission to use, copy, modify, and/or distribute this software for any
# purpose with or without fee is hereby granted.
#
# THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
# REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
# AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
# INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
# LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
# OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
# PERFORMANCE OF THIS SOFTWARE.
################################################################################

################################################################################
# Adds function call tracing for C++ function calls between compilation units.
#
# Assumed variables:
# - TRACE_TARGET: Variable that evaluates to the name of the executable target
#                 that is to be instrumented for tracing. All source files set
#                 on that target must be specified as absolute paths.
# - TARGET_FILE: Absolute path to a file with a list of the functions whose
#                calls shall be traceable. File must be readable. File contains
#                function descriptions in yaml format.
# - TRACE_NESTED_BUILD: Must not be set in any way.
# - TRACE_BUILD_VERBOSE: Optional, enables verbose output if set.
# - TRACE_MANGLING_RESOLUTION_ALGORITHM: Algorithm to use to find mangled names:
#   - "REUSE": Source files are compiled once (most at CMake configuration
#              time), this breaks the dependency resolution so change-based
#              build does not work anymore.
#   - "REBUILD": Source files are compiled twice. Dependencies are kept intact.
#                Redundant build can be mitigated by ccache.
#   This variable is optional, it defaults to REBUILD if not set.
#
# Usage:
# Ensure the variables are set, then include the subdirectory with this file as
# last step (after all targets have been created and all files and options have
# been set on them).
# Usage Notes:
# - All paths in command line arguments passed to CMake for the project this is
#   included in must be absolute paths.
# - Only works for debug builds.
#
################################################################################

##################################
# Parse the compile_commands.json file to locate the .o files that correspond
# to source files.
#
# Input parameters:
# - COMPILE_COMMANDS_FILE: Absolute path to the compile_commands.json file.
#
# Output parameters (variables set in the calling scope):
# - OBJECT_FILES_LIST_SOURCES: List of absolute paths of source files.
# - OBJECT_FILES_LIST_OBJECTS: List of absolute paths of object files. The path
#                              in index n of this list is the object file
#                              compiled from the source file in index n of
#                              OBJECT_FILES_LIST_SOURCES.
#
# In case the function fails (e.g. file can not be opened or parsing fails),
# execution is aborted immediately and the function does not return.
##################################
function(parse_compile_commands COMPILE_COMMANDS_FILE)
  set(OBJECT_FILES_LIST_SOURCES_TEMP)
  set(OBJECT_FILES_LIST_OBJECTS_TEMP)

  file(READ "${COMPILE_COMMANDS_FILE}" COMPILE_COMMANDS)

  string(REGEX MATCHALL "}," OBJECT_SEPARATOR_LIST "${COMPILE_COMMANDS}")
  list(LENGTH OBJECT_SEPARATOR_LIST OBJECT_SEPARATORS)

  foreach(SOURCE_FILE_INDEX RANGE ${OBJECT_SEPARATORS})
    set(CURRENT_DIR "")
    set(CURRENT_CMD "")
    set(CURRENT_FILE "")

    string(JSON CURRENT_DIR GET ${COMPILE_COMMANDS} ${SOURCE_FILE_INDEX} directory)
    string(JSON CURRENT_CMD GET ${COMPILE_COMMANDS} ${SOURCE_FILE_INDEX} command)
    string(JSON CURRENT_FILE GET ${COMPILE_COMMANDS} ${SOURCE_FILE_INDEX} file)

    if("${CURRENT_DIR}" STREQUAL "")

      message(SEND_ERROR "\"directory\" not set in file ${COMPILE_COMMANDS_FILE} for json object with index ${SOURCE_FILE_INDEX}.")

    elseif("${CURRENT_CMD}" STREQUAL "")

      message(SEND_ERROR "\"command\" not set in file ${COMPILE_COMMANDS_FILE} for json object with index ${SOURCE_FILE_INDEX}.")

    elseif("${CURRENT_FILE}" STREQUAL "")

      message(SEND_ERROR "\"file\" not set in file ${COMPILE_COMMANDS_FILE} for json object with index ${SOURCE_FILE_INDEX}.")

    else()

      separate_arguments(CURRENT_CMD)
      list(LENGTH CURRENT_CMD COMMAND_LENGTH)
      math(EXPR LAST_COMMAND_INDEX "${COMMAND_LENGTH} - 1" OUTPUT_FORMAT DECIMAL)
      list(FIND CURRENT_CMD "-o" OBJECT_FLAG_INDEX)

      if(OBJECT_FLAG_INDEX LESS 0)

        message(SEND_ERROR "No -o flag found in \"command\" of json object index ${SOURCE_FILE_INDEX} in file ${COMPILE_COMMANDS_FILE}.")

      elseif(${OBJECT_FLAG_INDEX} GREATER_EQUAL LAST_COMMAND_INDEX)

        message(SEND_ERROR "-o flag found in \"command\" of json object index ${SOURCE_FILE_INDEX} in file ${COMPILE_COMMANDS_FILE} is last part of command, missing object file path.")

      else()

        math(EXPR OBJECT_FILE_PATH_INDEX "${OBJECT_FLAG_INDEX} + 1" OUTPUT_FORMAT DECIMAL)
        list(GET CURRENT_CMD ${OBJECT_FILE_PATH_INDEX} OBJECT_FILE_PATH)
        string(PREPEND OBJECT_FILE_PATH "${CURRENT_DIR}/")

        if(NOT EXISTS "${OBJECT_FILE_PATH}")

          message(SEND_ERROR "Object file ${OBJECT_FILE_PATH} for json object with index ${SOURCE_FILE_INDEX} in file ${COMPILE_COMMANDS_FILE} has not been found.")

        else()

          list(APPEND OBJECT_FILES_LIST_SOURCES_TEMP "${CURRENT_FILE}")
          list(APPEND OBJECT_FILES_LIST_OBJECTS_TEMP "${OBJECT_FILE_PATH}")

        endif()
      endif()
    endif()

  endforeach()

  set(OBJECT_FILES_LIST_SOURCES ${OBJECT_FILES_LIST_SOURCES_TEMP} PARENT_SCOPE)
  set(OBJECT_FILES_LIST_OBJECTS ${OBJECT_FILES_LIST_OBJECTS_TEMP} PARENT_SCOPE)
endfunction()

##################################
# Actual activity.
##################################

# TRACE_BUILD_VERBOSE is only used as if-condition. This causes the CMake
# warning that it is not used. Suppress this warning.
if(DEFINED TRACE_BUILD_VERBOSE)
  set(SUPPRESS_UNUSED_VARIABLE_WARNING "${TRACE_BUILD_VERBOSE}")
endif()

if(NOT DEFINED TRACE_MANGLING_RESOLUTION_ALGORITHM)
  set(TRACE_MANGLING_RESOLUTION_ALGORITHM "REBUILD")
elseif("${TRACE_MANGLING_RESOLUTION_ALGORITHM}" STREQUAL "REUSE")
  # Ok
elseif("${TRACE_MANGLING_RESOLUTION_ALGORITHM}" STREQUAL "REBUILD")
  # Ok
else()
  message(FATAL_ERROR "Value ${TRACE_MANGLING_RESOLUTION_ALGORITHM} for TRACE_MANGLING_RESOLUTION_ALGORITHM invalid. Options are \"REUSE\" and \"REBUILD\".")
endif()


if(NOT DEFINED TRACE_TARGET)
  message(FATAL_ERROR "Variable \"TRACE_TARGET\" not set.")
elseif(NOT DEFINED TARGET_FILE)
  message(FATAL_ERROR "Variable \"TARGET_FILE\" not set.")
elseif(NOT EXISTS "${TARGET_FILE}")
  message(FATAL_ERROR "File ${TARGET_FILE} not found.")
else()

  # Set option to generate class structure files.
  # Needs to be set in normal and nested build so ccache will find the options
  # being the same.
  if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    set(COMPILER_SELECTION_FLAG "gcc")
    target_compile_options("${TRACE_TARGET}" PUBLIC "-fdump-lang-class")
  elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(COMPILER_SELECTION_FLAG "clang")
  else()
    message(FATAL_ERROR "C++ compiler ${CMAKE_CXX_COMPILER_ID} is not supported for tracing.")
  endif()

  # Setup wrapper for ccache.
  # Approach taken from https://crascit.com/2016/04/09/using-ccache-with-cmake.
  find_program(CCACHE_PROGRAM ccache)
  if(CCACHE_PROGRAM)
    set(CXX_LAUNCHER "${CCACHE_PROGRAM}")
  else()
    set(CXX_LAUNCHER "")
    if("${TRACE_MANGLING_RESOLUTION_ALGORITHM}" STREQUAL "REBUILD")
      message(WARNING "ccache not found. This may cause duplicated compilation.")
    endif()
  endif()

  configure_file(launchcxx.in launchcxx)
  execute_process(COMMAND chmod a+rx "${CMAKE_CURRENT_BINARY_DIR}/launchcxx")
  set_target_properties(${TRACE_TARGET} PROPERTIES CXX_COMPILER_LAUNCHER "${CMAKE_CURRENT_BINARY_DIR}/launchcxx")


  ## Location to put generated file with callout function declarations to.
  set(CALLOUT_HEADER_FILENAME "tracing_callouts.h")
  set(CALLOUT_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/generated/${CALLOUT_HEADER_FILENAME}")
  ## Location to put generated file with callout function definitions to.
  set(CALLOUT_FILE "${CMAKE_CURRENT_SOURCE_DIR}/generated/tracing_callouts.cpp")

  # It is important that CALLOUT_HEADER and CALLOUT_FILE are in the same
  # directory as CALLOUT_FILE will include CALLOUT_HEADER with #include "" which
  # searches the same directory first.
  target_sources(${TRACE_TARGET} PRIVATE ${CALLOUT_FILE})

  set(TARGET_TYPE "DEFAULT")
  get_target_property(TARGET_TYPE ${TRACE_TARGET} TYPE)
  if(NOT "${TARGET_TYPE}" STREQUAL "EXECUTABLE")
    message(FATAL_ERROR "Target is not an executable, type is ${TARGET_TYPE}.")
  elseif(DEFINED TRACE_NESTED_BUILD AND TRACE_NESTED_BUILD)
    # nested build inspired by https://stackoverflow.com/questions/36084785/
    # building-a-tool-immediately-so-it-can-be-used-later-in-same-cmake-run

    # Skip linking in nested build (it would fail anyway with undefined
    # references), compilation is sufficient.
    # This could be achieved by creating a second target that basically
    # duplicates target but is an object library instead of an executable. But
    # there is no sane way to copy all properties from the original to the new
    # target so this workaround was chosen.
    target_link_options(${TRACE_TARGET} BEFORE PUBLIC "--version")

    # Clear cache so next normal build does not invoke the nested build.
    unset(TRACE_NESTED_BUILD CACHE)

    return() # No need to do anything else in the nested build.
  else()
    ##################################
    # Generation of callout code.
    ##################################

    set(GENERATION_RESULT -1)

    execute_process(COMMAND "${CMAKE_CURRENT_SOURCE_DIR}/generate_callouts.sh" "${TARGET_FILE}" "${CALLOUT_HEADER}" "${CALLOUT_FILE}" "${CALLOUT_HEADER_FILENAME}" RESULT_VARIABLE GENERATION_RESULT)

    if(NOT "${GENERATION_RESULT}" EQUAL 0)
      message(FATAL_ERROR "Generating callouts failed.")
    endif()

    ##################################
    # Start nested build.
    ##################################

    # Get command line arguments passed to current invocation of CMake.
    execute_process(COMMAND bash -c "tr '\\0' ' ' < /proc/$PPID/cmdline"
                    OUTPUT_VARIABLE COMMAND_LINE)
    set(WORKDIR ${CMAKE_BINARY_DIR})

    separate_arguments(COMMAND_LINE)
    list(GET COMMAND_LINE 0 FIRST_ITEM)
    if(${FIRST_ITEM} STREQUAL "cmake")
      list(POP_FRONT COMMAND_LINE)
    endif()
    execute_process(COMMAND ${CMAKE_COMMAND} ${COMMAND_LINE}
                            -DTRACE_NESTED_BUILD=ON
                            ${CMAKE_SOURCE_DIR}
                            -DCMAKE_EXPORT_COMPILE_COMMANDS=1
                   WORKING_DIRECTORY "${WORKDIR}")
    execute_process(COMMAND ${CMAKE_COMMAND} --build . --target ${TRACE_TARGET}
                    WORKING_DIRECTORY "${WORKDIR}")

    ##################################
    # Parse compile_commands.json
    ##################################

    parse_compile_commands("${CMAKE_BINARY_DIR}/compile_commands.json")

    ##################################
    # Implementation of TRACE_MANGLING_RESOLUTION_ALGORITHM=REUSE 
    ##################################

    if("${TRACE_MANGLING_RESOLUTION_ALGORITHM}" STREQUAL "REUSE")

      get_target_property(SOURCE_LIST ${TRACE_TARGET} SOURCES)

      foreach(SOURCE_PATH OBJECT_FILE_PATH IN ZIP_LISTS OBJECT_FILES_LIST_SOURCES OBJECT_FILES_LIST_OBJECTS)
        list(FIND SOURCE_LIST ${SOURCE_PATH} FILE_INDEX)
        if(FILE_INDEX GREATER_EQUAL 0)
          list(REMOVE_AT SOURCE_LIST ${FILE_INDEX})
          list(INSERT SOURCE_LIST ${FILE_INDEX} ${OBJECT_FILE_PATH})
          set_property(SOURCE ${OBJECT_FILE_PATH} APPEND PROPERTY OBJECT_DEPENDS ${SOURCE_PATH})
        endif()
      endforeach()

      set_property(TARGET ${TRACE_TARGET} PROPERTY SOURCES ${SOURCE_LIST})
      set_target_properties(${TRACE_TARGET} PROPERTIES LINK_DEPENDS "${OBJECT_FILES_LIST_SOURCES}")
      # Set linker language explicitly. As all source files were replaced by
      # object files, CMake may no longer be able to figure out the language by
      # itself.
      set_property(TARGET ${TRACE_TARGET} PROPERTY LINKER_LANGUAGE CXX)

    endif()

    ##################################
    # Generation of wrapper code.
    ##################################

    set(CALLOUT_INDEX)
    set(CALLOUT_OBJECT)

    list(FIND OBJECT_FILES_LIST_SOURCES ${CALLOUT_FILE} CALLOUT_INDEX)

    if(CALLOUT_INDEX LESS 0)
      message(FATAL_ERROR "File could not be generated.")
    else()
      list(GET OBJECT_FILES_LIST_OBJECTS ${CALLOUT_INDEX} CALLOUT_OBJECT)
      list(REMOVE_AT OBJECT_FILES_LIST_SOURCES ${CALLOUT_INDEX})
      list(REMOVE_AT OBJECT_FILES_LIST_OBJECTS ${CALLOUT_INDEX})
    endif()

    # Paths to class structure files, separated by newlines.
    set(OBJECT_FILES_LIST_CLASS_STRUCTURE)

    # Paths to binary files, separated by newlines.
    set(OBJECT_FILES_LIST_BINARIES)

    foreach(OBJECT_FILE_PATH ${OBJECT_FILES_LIST_OBJECTS})
      string(REGEX REPLACE "\.o$" "\.cpp\.001l\.class" STRUCTURE_FILE_PATH "${OBJECT_FILE_PATH}")
      if(NOT EXISTS "${STRUCTURE_FILE_PATH}")
        message(WARNING "Class structure file ${STRUCTURE_FILE_PATH} not found. Skipping.")
      else()
        string(APPEND OBJECT_FILES_LIST_CLASS_STRUCTURE "${STRUCTURE_FILE_PATH}\n")
      endif()
      string(APPEND OBJECT_FILES_LIST_BINARIES "${OBJECT_FILE_PATH}\n")
    endforeach()

    # Input to code generation.
    ## List of class structure files.
    set(CLASS_STRUCTURE_LIST_FILE "${CMAKE_BINARY_DIR}/Tracing/class_structure_files_list.txt")
    ## List of compiled binary files.
    set(BINARY_LIST_FILE "${CMAKE_BINARY_DIR}/Tracing/binary_files_list.txt")
    ## Location to put output file with mangled names of wrapped functions to.
    set(FUNCTIONS_FILE "${CMAKE_BINARY_DIR}/Tracing/functions_mangled.txt")
    ## Location to put generated file with wrapper functions to.
    set(WRAPPER_FILE "${CMAKE_BINARY_DIR}/Tracing/tracing_wrappers.cpp")

    file(WRITE "${CLASS_STRUCTURE_LIST_FILE}" "${OBJECT_FILES_LIST_CLASS_STRUCTURE}")

    file(WRITE "${BINARY_LIST_FILE}" "${OBJECT_FILES_LIST_BINARIES}")

    set(GENERATION_RESULT -1)

    set(VERBOSE "False")
    if(DEFINED TRACE_BUILD_VERBOSE)
      set(VERBOSE "True")
    endif()

    execute_process(COMMAND "${CMAKE_CURRENT_SOURCE_DIR}/generate_wrappers.sh" "${CLASS_STRUCTURE_LIST_FILE}" "${BINARY_LIST_FILE}" "${TARGET_FILE}" "${FUNCTIONS_FILE}" "${WRAPPER_FILE}" "${COMPILER_SELECTION_FLAG}" ${CALLOUT_OBJECT} "${VERBOSE}" RESULT_VARIABLE GENERATION_RESULT)

    if(NOT "${GENERATION_RESULT}" EQUAL 0)
      message(FATAL_ERROR "Generating code for tracing failed.")
    endif()

    ##################################
    # Process generation output.
    ##################################

    target_sources("${TRACE_TARGET}" PUBLIC "${WRAPPER_FILE}")

    # Read mangled names for --wrap linker option.
    if(NOT EXISTS "${FUNCTIONS_FILE}")
      message(FATAL_ERROR "File ${FUNCTIONS_FILE} removed or not generated.")
    endif()
    file(STRINGS "${FUNCTIONS_FILE}" FUNCTIONS_LIST)
    foreach(CURRENT_FUNCTION ${FUNCTIONS_LIST})
      string(STRIP "${CURRENT_FUNCTION}" CURRENT_FUNCTION)
      set(CURRENT_OPTION "-Wl,--wrap=${CURRENT_FUNCTION}")
      if(DEFINED TRACE_BUILD_VERBOSE)
        message(STATUS "Note: current link option: ${CURRENT_OPTION}")
      endif()
      target_link_options("${TRACE_TARGET}" PUBLIC "${CURRENT_OPTION}")
    endforeach()
  endif()
endif()