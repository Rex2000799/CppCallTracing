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
# Contains function GenerateVtableUpdateClang() that generates code to update
# the vtable so calls to virtual functions are redirected to the wrapper
# functions.
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
def GenerateVtableUpdateClang(update_list):
  # TODO: implement for clang

  res = ""

  return res
