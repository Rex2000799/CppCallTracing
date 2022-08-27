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
# Support class for storing information about a wrapper to trace calls to a
# C++ function.
#
################################################################################

from parsers.utils import GetClassName

########################################
# Represents information about one C++ function wrapper.
#
# member variables:
# - prod_name (string): unmangled name of the wrapped function
# - mangled_name (string): mangled name of the wrapped function
# - rettype (string): The return type. None if the function returns void.
# - params (list of strings): The types of parameter in the same order as in
#                             code/config. Each string is the type of one
#                             parameter.
# - entry_callout (string): mangled name of the function to call before entering
#                           the wrapped function
# - exit_callout (string): mangled name of the function to call after returning
#                          from the wrapped function
# - include (string): Include for the header with declaration of the wrapped
#                     function.
########################################
class WrapperInfo:
  ######################################
  # Creates an instance.
  #
  # Input parameters:
  # - func_info: ConfigInfo instance
  # - mangled_name: the mangled name of the wrapped function
  #
  ######################################
  def __init__(self, func_info, mangled_name):
    self.prod_name = func_info.name

    self.mangled_name = mangled_name

    if func_info.rettype.strip() == "void":
      self.rettype = None
    else:
      self.rettype = func_info.rettype.strip()


    if func_info.level == "const":
      self.params = [GetClassName(func_info.name) + " const *"]
    elif func_info.level == "member":
      self.params = [GetClassName(func_info.name) + " *"]
    else: # func_info.level == "free"
      self.params = [] # Nothing to do, no this pointer.

    self.params = self.params + func_info.parameters

    self.include = func_info.include

    self.entry_callout = None

    self.exit_callout = None
