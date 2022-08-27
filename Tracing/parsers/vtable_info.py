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
# Support classes for storing information about a vtable.
#
################################################################################

########################################
# Represents information about one vtable.
#
# member variables:
# - mangled_name (string): mangled name of the vtable
# - entries (list of strings): The names of the functions in the vtable. The
#                              index in this list is the index of this function
#                              in the vtable.
########################################
class VtableInfo:
  ######################################
  # Creates an instance.
  #
  # parameters:
  # - mangled_name (string): the mangled name of the vtable
  ######################################
  def __init__(self, mangled_name):
    self.mangled_name = mangled_name
    self.entries = []

  ######################################
  # Adds a function to the vtable
  #
  # parameters:
  # - function_name (string): the unmangled name of the function to add
  ######################################
  def AddEntry(self, function_name):
    self.entries.append(function_name)

