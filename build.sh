#!/bin/bash
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

SourceDir=$(realpath .)
BuildDir=$(realpath ./build)

# Clean build only required if at least one of the following is done
# - test/traced_functions.yml is changed
# - TRACE_MANGLING_RESOLUTION_ALGORITHM is set to REUSE
rm -rf build

cmake -D TRACE_BUILD_VERBOSE=True -D CMAKE_C_COMPILER=gcc -D CMAKE_CXX_COMPILER=g++ -S $SourceDir -B $BuildDir
cmake --build $BuildDir --target TraceTest
