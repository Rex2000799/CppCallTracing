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
# Contains function GenerateVtableUpdateGcc() that generates code to update the
# vtable so calls to virtual functions are redirected to the wrapper functions.
#
# Parameters:
# - update_list (list of VtableUpdate objects): Information about the updates to
#                                               generate code for.
#
# Returns a string that contains the generated file contents. Contents are
# generated in a way that assumes that they are appended to the file that
# defines the __wrap_ functions.
#
################################################################################

from generators.utils import GenerateCallbackSingleton

########################################
# Main function if this file, see beginning of file for documentation.
########################################
def GenerateVtableUpdateGcc(update_list):
  res = "extern \"C\" {\n\n\n"

  # Forward declarations of vtables.
  for current_vtable in update_list:
    res = res + "int * " + current_vtable.mangled_name + "[" + str(current_vtable.size) + "];\n\n"

  res = res + "\n\n"

  # Function to update the vtables.
  res = res + "void UpdateVtable() {\n"

  for current_vtable in update_list:
    for current_entry in current_vtable.updates:
      res = res + "  " + current_vtable.mangled_name + "[" + str(current_entry.index) + "] = reinterpret_cast<int *>(&" + current_entry.target + ");\n"

    res = res + "\n\n"

  res = res + "}\n\n"


  res = res + "}  // extern C\n"

  res = res + "\n\n\n"

  # Singleton to call the update function.
  res = res + "namespace tracing {\n\n"
  res = res + GenerateCallbackSingleton("UpdateVtable")
  res = res + "}  // namespace tracing\n"

  return res
