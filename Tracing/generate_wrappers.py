#!/usr/bin/env python3
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
# Generates wrappers for tracing C++ function calls.
#
# Commandline parameters (order is relevant):
# argv[1]: Absolute path to the file with the list of class structure files.
#          This file contains the absolute paths of the class structure files,
#          each path in one line with nothing else on it. Must be accessible
#          for read, so must be all listed files.
# argv[2]: Absolute path to the file with the list of object files. This file
#          contains the absolute paths of the object files, each path in one
#          line with nothing else on it. Must be accessible for read, so must be
#          all listed files.
# argv[3]: Absolute path to the file with the list of functions to trace. This
#          file contains information about traced functions in yaml format. Must
#          be accessible for read.
# argv[4]: Absolute path to the file to which the mangled names of wrapped
#          functions are written to. In this file, one name will be written per
#          line with nothing else on the line. Must be accessible for write.
# argv[5]: Absolute path to which the file with the __wrap_ function definitions
#          will be generated. Must be accessible for write.
# argv[6]: "gcc" if the compiler is gcc, "clang" if the compiler is clang.
# argv[7]: Absolute path of the object file that was compiled from the callout
#          definition source file. Must not be present in the list referred to
#          by argv[2].
# argv[8]: Flag to mark if verbose output shall be printed ("True") or not
#          ("False").
#
################################################################################

import sys
from os import access, R_OK, W_OK
from os.path import isfile

from parsers.parser_nm import ParseBinaries
from parsers.parser_function_list import ParseFunctionList
from parsers.parameters import CompareParams
from parsers.function_info import CalloutInfo
from parsers.parser_structure_gcc import ParseStructureFilesGcc
from parsers.parser_structure_clang import ParseStructureFilesClang

from generators.utils import GenerateCalloutNames
from generators.wrapper_generator import GenerateWrappers
from generators.vtable_update_generator_gcc import GenerateVtableUpdateGcc
from generators.vtable_update_generator_clang import GenerateVtableUpdateClang

from wrapper_info import WrapperInfo
from vtable_update_info import VtableUpdate


########################################
# Parses a file that contains paths to other files and does access checks.
#
# input parameters:
# - path: string with absolute path to the file to parse.
#
# Returns a list of paths read from the file.
########################################
def ParseListFile(path):
  result = []

  # Check access now. No robustness about parallel changes desired (would only
  # boil down to a different error message, failure to open the file can not
  # be handled any other way because the information from the file is needed).
  if isfile(path.strip()) and access(path.strip(), R_OK):
    with open(path.strip(), 'r') as list_file:
      for line in list_file:
        if isfile(line.strip()) and access(line.strip(), R_OK):
          result.append(line.strip())
        else:
          message = "Failed to open file \"" + line.strip()
          message = message + "\" (read from file \"" + path.strip()
          message = message + "\") for reading"
          print(message)
          sys.exit(1)
  else:
    message = "Failed to open file \"" + path.strip()
    message = message + "\" for reading."
    print(message)
    sys.exit(1)

  return result


########################################
# Parses a file that contains paths to other files and does access checks.
#
# input parameters:
# - functions (list of ConfigInfo): Information about all traced functions.
#
# Returns a list of full names (full namespaces, no leading ::) of classes that
# have traced functions (list of strings, each string one name).
########################################
def ExtractClassNames(functions):
  result = []
  for current in functions:
    if (current.level == "member") or (current.level == "const"):
      class_name = current.name.rsplit("::", 1)[0].strip()
      if class_name not in result:
        result.append(class_name)
  return result


## Evaluate command line arguments.

# argv[0] is script name.
if len(sys.argv) != 9:
  print("Wrong number of parameters passed.")
  sys.exit(1)


# List of absolute paths to class structure files.
structure_file_list = ParseListFile(sys.argv[1])


# List of absolute paths to object files.
object_file_list = ParseListFile(sys.argv[2])


# Absolute path to yaml file with configurations.
config_path = sys.argv[3].strip()

# List of ConfigInfo
traced_function_list = ParseFunctionList(config_path)

if traced_function_list == None:
  # Error message was already printed by ParseFunctionList()
  sys.exit(1)

# Names of the traced production code functions (list of strings).
traced_function_names = []

# Names of the callout functions (list of strings).
callout_function_names = []

for current_function in traced_function_list:
  # Prevent duplicates (e.g. for overloads).
  if current_function.name not in traced_function_names:
    traced_function_names.append(current_function.name)

  callout_names = GenerateCalloutNames(current_function.name, current_function.parameters)
  callout_function_names.append(callout_names.entry_name)
  callout_function_names.append(callout_names.exit_name)

# List of strings (each string the full name (all namespaces, no leading ::) of
# a class that has at least one traced member function).
relevant_class_list = ExtractClassNames(traced_function_list)


# Absolute path to file to write mangled names to.
name_list_file = ""
# Absolute path to the directory where that file is in (used as working
# directory) for creation of other files.
working_directory = ""

if access(sys.argv[4].strip().rsplit("/", 1)[0], W_OK):
  name_list_file = sys.argv[4].strip()
  working_directory = sys.argv[4].strip().rsplit("/", 1)[0]
else:
  message = "Failed to create/write file \"" + sys.argv[4].strip()
  message = message + "\" (fourth argument)."
  print(message)
  sys.exit(1)


# Absolute path to file to generate the code of wrapper functions to.
code_file = ""

if access(sys.argv[5].strip().rsplit("/", 1)[0], W_OK):
  code_file = sys.argv[5].strip()
else:
  message = "Failed to create/write file \"" + sys.argv[5].strip()
  message = message + "\" (fifth argument)."
  print(message)
  sys.exit(1)


if sys.argv[6].strip() != "gcc" and sys.argv[6].strip() != "clang":
  message = "Invalid compiler selection \"" + sys.argv[6].strip()
  message = message + "\" (seventh argument) passed. Options are \"gcc\" and"
  message = message + " \"clang\"."
  print(message)
  sys.exit(1)

used_compiler = sys.argv[6].strip()


# Absolute path to the object file with the callouts to be called from the
# wrappers.
callout_object_file = ""

if isfile(sys.argv[7].strip()) and access(sys.argv[7].strip(), R_OK):
  callout_object_file = sys.argv[7].strip()
else:
  message = "File \"" + sys.argv[7].strip() + "\" can not be accessed."
  print(message)
  sys.exit(1)


verbose_logging = False

if sys.argv[8] == "True":
  verbose_logging = True


## Parse binaries.

# Dict (unmangled function name) -> (list of BinaryInfo)
function_info = ParseBinaries(object_file_list, traced_function_names, working_directory)

if function_info == None:
  print("Parsing nm output failed.")
  sys.exit(1)

if verbose_logging:
  for current_function in function_info:
    if function_info[current_function] == None:
      message = "No overload found for function \"" + current_function
      message = message + "\" with parameters " + str(params) + "."
      print(message)
    else:
      for current_overload in function_info[current_function]:
        mangled_name = current_overload.mangled_name
        params = current_overload.params
        message = "Function \"" + current_function + "\" with parameters "
        message = message + str(params) + " maps to mangled name \""
        message = message + mangled_name + "\"."
        print(message)


# Dict (unmangled callout name) -> (list of BinaryInfo)
callout_info = ParseBinaries([callout_object_file], callout_function_names, working_directory)

if callout_info == None:
  print("Parsing nm output failed.")
  sys.exit(1)


## Match up between production-code functions, wrappers and callouts.

# Information to generate wrappers. List of WrapperInfo instances.
wrapper_info = []
# List of mangled names of wrapped functions. List of strings.
wrapper_list = []

success = True

for current_function in traced_function_list:
  info = None
  if (current_function.name not in function_info) or (function_info[current_function.name] == None):
    message = "Function \"" + current_function.name
    message = message + "\" to trace has not been found in binaries."
    print(message)
    success = False
    # Do not break loop here to be able to report other errors.
  else:
    match = False
    for current_overload in function_info[current_function.name]:
      if verbose_logging:
        message = "For function: \"" + current_function.name + "\": "
        message = message + "Comparing \"" + str(current_function.parameters)
        message = message + "\" (from file " + config_path + ") and \""
        message = message + str(current_overload.params)
        message = message + "\" (from binaries) to find matching overload."
        print(message)

      if CompareParams(current_function.parameters, current_overload.params):
        info = WrapperInfo(current_function, current_overload.mangled_name)
        match = True
        if verbose_logging:
          print("Selected this as matching overload.")
        break

    if not match:
      message = "No matching overload for function \""
      message = message + current_function.name
      message = message + "\" found in binaries."
      print(message)
      success = False
    else:
      match = False

      callout_names = GenerateCalloutNames(current_function.name, current_function.parameters)
      entry_callout = callout_names.entry_name
      exit_callout = callout_names.exit_name

      if (entry_callout in callout_info) and (exit_callout in callout_info):
        if len(callout_info[entry_callout]) == 0:
          if verbose_logging:
            params = str(current_function.parameters)
            message = "Entry callout for function \"" + current_function.name
            message = message + "\" with parameters " + params + "\" has not"
            message = message + " been found in binary. Callout name is \""
            message = message + entry_callout + "\"."
            print(message)
        elif len(callout_info[entry_callout]) > 1:
          if verbose_logging:
            params = str(current_function.parameters)
            message = "Multiple overloads of entry callout for function \""
            message = message + current_function.name + "\" with parameters "
            message = message + params + " have been found. Expected only "
            message = message + "one but found:\n"
            for log_entry in callout_info[entry_callout]:
              message = message + "- \"" + log_entry.mangled_name + "\"\n"
            message = message + "Callout name is \"" + entry_callout + "\"."
            print(message)
        elif len(callout_info[exit_callout]) == 0:
          if verbose_logging:
            params = str(current_function.parameters)
            message = "Exit callout for function \"" + current_function.name
            message = message + "\" with parameters " + params + "\" has not"
            message = message + " been found in binary. Callout name is \""
            message = message + exit_callout + "\"."
            print(message)
        elif len(callout_info[exit_callout]) > 1:
          if verbose_logging:
            params = str(current_function.parameters)
            message = "Multiple overloads of exit callout for function \""
            message = message + current_function.name + "\" with parameters "
            message = message + params + " have been found. Expected only one "
            message = message + "but found:\n"
            for log_entry in callout_info[exit_callout]:
              message = message + "- \"" + log_entry.mangled_name + "\"\n"
            message = message + "Callout name is \"" + exit_callout + "\"."
            print(message)
        else:
          info.entry_callout = callout_info[entry_callout][0].mangled_name
          info.exit_callout = callout_info[exit_callout][0].mangled_name
          match = True


      if not match:
        message = "No matching callout for function \""
        message = message + current_function.name
        message = message + "\" found in binaries."
        print(message)
        success = False
      else:
        wrapper_info.append(info)
        wrapper_list.append(info.mangled_name)


if not success:
  # Error message has been printed in loop.
  sys.exit(1)



## Generate wrapper code.
wrapper_code = GenerateWrappers(wrapper_info)



## Parse class structure files.

# dict(string -> VtableInfo)
# string = full name (full namespace, no leading ::) of class
vtable_info = {}

if used_compiler == "gcc":
  vtable_info = ParseStructureFilesGcc(structure_file_list, relevant_class_list)
else: # used_compiler == "clang":
  message = "Support for clang compiler has not been added yet."
  print(message)
  vtable_info = None
  # vtable_info = ParseStructureFilesClang(structure_file_list, relevant_class_list)

if vtable_info == None:
  # Error message has been printed in ParseStructureFiles*().
  sys.exit(1)

if verbose_logging:
  for current_class in vtable_info:
    message = "Found vtable for class \"" + current_class + "\":\n"

    message = message + "Mangled name of vtable: \""
    message = message + vtable_info[current_class].mangled_name + "\".\n"

    message = message + "Entries:\n"
    for current_vtable_entry in vtable_info[current_class].entries:
      message = message + "- " + current_vtable_entry + "\n"

    print(message)


# List of VtableUpdate.
vtable_updates = []

## Match vtable with __wrap_ functions.
for current_class in vtable_info:
  current_update = VtableUpdate(vtable_info[current_class].mangled_name, len(vtable_info[current_class].entries))
  index_counter = 0

  for current_vtable_entry in vtable_info[current_class].entries:
    for current_wrapper in wrapper_info:
      if current_wrapper.prod_name == current_vtable_entry:
        current_update.AddEntryUpdate("__wrap_" + current_wrapper.mangled_name, index_counter)
        break

    index_counter = index_counter + 1

  if len(current_update.updates) > 0:
    vtable_updates.append(current_update)


## Generate vtable update code.

vtable_update_code = ""

if used_compiler == "gcc":
  vtable_update_code = GenerateVtableUpdateGcc(vtable_updates)
else: # used_compiler == "clang"
  message = "Support for clang compiler has not been added yet."
  print(message)
  vtable_update_code = ""
  # vtable_update_code = GenerateVtableUpdateClang(vtable_updates)


## Write list of mangled names of wrapped functions to file.
name_file_content = ""
first = True
for current_mangled_name in wrapper_list:
  if first:
    first = False
  else:
    name_file_content = name_file_content + "\n"
  name_file_content = name_file_content + current_mangled_name.strip()

with open(name_list_file, "w") as name_file:
  name_file.write(name_file_content)


## Write code to file
with open(code_file, "w") as wrapper_file:
  wrapper_file.write(wrapper_code + "\n\n\n\n\n" + vtable_update_code)


sys.exit(0)
