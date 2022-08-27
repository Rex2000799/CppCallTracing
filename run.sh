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

./build/TraceTest > temp.txt

cmp temp.txt expected.txt  > /dev/null

if [ $? = 0 ]; then
  echo "========= TEST PASSED ========="
  echo "Output matches expectation, tracing callouts called"
else
  echo "========= TEST FAILED ========="
  echo "Output does not match expectation, diff is:"
  echo ""
  diff temp.txt expected.txt
fi

rm temp.txt
