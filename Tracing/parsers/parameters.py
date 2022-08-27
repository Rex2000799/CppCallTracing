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
# Contains function CompareParams() that allows to compare if the parameter
# lists of two functions are the same.
#
# Input parameters:
# - first (list of strings): list of parameter types, one string per parameter
# - second (list of strings): list of parameter types, one string per parameter
#
# The functions are considered to be equal if the number of parameters is the
# same and type n of the first function (list) is the same type with the same
# qualifiers as type n of the second function (list).
#
# Returns True if the functions compare equal according do this, else returns
# False.
################################################################################

import itertools
from parsers.utils import NormalizeParameterType

def CompareParams(first, second):
  if len(first) != len(second):
    return False
  else:
    for (cur_first, cur_second) in zip(first, second):
      norm_f = NormalizeParameterType(cur_first)
      norm_s = NormalizeParameterType(cur_second)
      if norm_f != norm_s:
        return False

  return True
