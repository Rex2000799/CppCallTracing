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
# Support class for storing information about updating the vtable.
#
################################################################################

########################################
# Represents one update of one vtable.
#
# member variables:
# - target (string): mangled name of the function to put into the vtable.
# - index (int): The index in the vtable to put the function to.
########################################
class VtableEntryUpdate:
  ######################################
  # Creates an instance.
  #
  # Input parameters:
  # - target (string): Mangled name of the function to put into the vtable.
  # - index (int): Index in the vtable to put the function to.
  #
  ######################################
  def __init__(self, target, index):
    self.target = target
    self.index = index


########################################
# Represents information on how to update one vtable.
#
# member variables:
# - mangled_name (string): mangled name of the vtable.
# - size (int): The number of entries in the vtable.
# - updates (list of VtableEntryUpdate): updates to do to the vtable.
########################################
class VtableUpdate:
  ######################################
  # Creates an instance.
  #
  # Input parameters:
  # - name (string): Mangled name of the vtable.
  # - size (int): Number of entries in the vtable.
  #
  ######################################
  def __init__(self, name, size):
    self.mangled_name = name
    self.size = size
    self.updates = []

  ######################################
  # Adds one update of one entry.
  #
  # Input parameters:
  # - target (string): Mangled name of the function to put into the vtable.
  # - index (int): Index in the vtable to put the function to.
  #
  ######################################
  def AddEntryUpdate(self, target, index):
    assert index < self.size, "Vtable update index out of range of vtable"

    self.updates.append(VtableEntryUpdate(target, index))
