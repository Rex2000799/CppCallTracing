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

cmake_minimum_required(VERSION 3.24.0)

project(TraceTest)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)


set(CMAKE_BUILD_TYPE "Debug")

set(TARGET TraceTest)

add_executable(${TARGET} ${CMAKE_CURRENT_SOURCE_DIR}/Test/test.cpp ${CMAKE_CURRENT_SOURCE_DIR}/Test/main.cpp)

target_include_directories(${TARGET} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Test)

# Everything up to here is the (admittedly very small) CMake project as it would
# be without tracing of function calls. The following lines are what enables
# tracing.

set(TRACE_TARGET ${TARGET})
set(TARGET_FILE "${CMAKE_CURRENT_SOURCE_DIR}/Test/traced_functions.yml")

add_subdirectory(Tracing)
