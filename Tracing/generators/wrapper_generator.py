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
# Contains function GenerateWrappers() that generates the wrapper functions for
# the wrap linker option.
#
# Parameters:
# - wrapper_list (list of WrapperInfo objects): Information about the wrappers
#                                               to generate.
#
# Returns a string that contains the generated file contents.
#
################################################################################

import itertools
from generators.utils import GenerateIncludes

########################################
# Stores information about types for one wrapper.
#
# member variables:
# - rettype_wrapper (string): The alias for the return type that is used for the
#                             wrapper.
# - rettype_callout (string): The alias for the return type that is used for the
#                             callout.
# - params_wrapper (list of strings): The aliases for the parameter types used
#                                     for the wrapper in the same order as
#                                     respective parameters in the code/config.
#                                     Each string is one alias.
# - params_callout (list of strings): The aliases for the parameter types used
#                                     for the wrapper in the same order as
#                                     respective parameters in the code/config.
#                                     Each string is one alias.
########################################
class WrapperTypeInfo:
  ######################################
  # Creates an instance.
  #
  # Input parameters:
  # - rettype_wrapper: Alias of the return type to use for wrapper.
  # - rettype_callout: Alias of the return type to use for callout.
  #
  ######################################
  def __init__(self, rettype_wrapper, rettype_callout):
    self.rettype_wrapper = rettype_wrapper
    self.rettype_callout = rettype_callout
    self.params_wrapper = []
    self.params_callout = []

  ######################################
  # Adds a parameter alias.
  #
  # Input parameters:
  # - param_wrapper: Alias of the parameter to use for wrapper.
  # - param_callout: Alias of the parameter to use for callout.
  #
  ######################################
  def AddParameter(self, param_wrapper, param_callout):
    self.params_wrapper.append(param_wrapper)
    self.params_callout.append(param_callout)


########################################
# Generates aliases for parameter and return types required by a wrapper.
# Uses the mangled name of the wrapped function as this is unique.
#
# Input parameters:
# - wrapper_info (WrapperInfo instance): Information about the wrapper.
#
# Returns a WrapperTypeInfo object with the type aliases for the wrapper.
########################################
def GenerateWrapperTypeAliases(wrapper_info):
  if wrapper_info.rettype == None:
    return_type_alias_wrapper = "void"
    return_type_alias_callout = "void"
  else:
    return_type_alias_wrapper = "ReturnType" + wrapper_info.mangled_name + "Wrapper"
    return_type_alias_callout = "ReturnType" + wrapper_info.mangled_name + "Callout"
  result = WrapperTypeInfo(return_type_alias_wrapper, return_type_alias_callout)

  count = 1
  for current_param in wrapper_info.params:
    wrapper_alias = "Param" + str(count) + wrapper_info.mangled_name + "Wrapper"
    callout_alias = "Param" + str(count) + wrapper_info.mangled_name + "Callout"
    result.AddParameter(wrapper_alias, callout_alias)
    count = count + 1

  return result


########################################
# Main function if this file, see beginning of file for documentation.
########################################
def GenerateWrappers(wrapper_list):
  res = "// ATTENTION: GENERATED FILE, DO NOT MODIFY.\n"

  res = res + "\n\n"

  res = res + "#include <utility>  // std::move\n"
  res = res + "\n\n"
  res = res + GenerateIncludes(wrapper_list)

  res = res + "\n\n"

  # Using aliases for parameter types to avoid issues with name mangling of ::
  # in extern C block.
  res = res + "using std::move;"

  res = res + "\n\n"

  # List of information about wrapper type aliases. Order is the same as the
  # wrapper list.
  alias_info = []

  for current_wrapper in wrapper_list:
    current_info = GenerateWrapperTypeAliases(current_wrapper)
    alias_info.append(current_info)

    if current_wrapper.rettype != None:
      res = res + "using " + current_info.rettype_wrapper + " = " + current_wrapper.rettype + ";\n"
      # Make && to & so calling the callout does not move away a move-only
      # parameter.
      res = res + "using " + current_info.rettype_callout + " = " + current_wrapper.rettype.replace("&&", "&") + ";\n"

    for (current_alias, current_type) in zip(current_info.params_wrapper, current_wrapper.params):
      res = res + "using " + current_alias + " = " + current_type + ";\n"
    for (current_alias, current_type) in zip(current_info.params_callout, current_wrapper.params):
      # Make && to & so calling the callout does not move away a move-only
      # parameter.
      res = res + "using " + current_alias + " = " + current_type.replace("&&", "&") + ";\n"

    res = res + "\n"

  res = res + "\n\n"

  res = res + "extern \"C\" {\n\n\n"

  # Forward declarations of __real_
  for (current_wrapper, current_alias) in zip(wrapper_list, alias_info):
    decl = current_alias.rettype_wrapper + " __real_" + current_wrapper.mangled_name
    decl = decl + "("
    first = True
    for current_param_alias in current_alias.params_wrapper:
      if first:
        first = False
      else:
        decl = decl + ", "
      decl = decl + current_param_alias
    decl = decl + ");\n"
    res = res + decl

  res = res + "\n\n\n"

  # Definitions of __wrap_
  for (current_wrapper, current_alias) in zip(wrapper_list, alias_info):
    # Forward declaration of callouts. Including the header does not work as
    # the callouts are in the actual namespace there.
    res = res + "void " + current_wrapper.entry_callout + "("
    first = True
    for current_param_alias in current_alias.params_callout:
      if first:
        first = False
      else:
        res = res + ", "
      res = res + current_param_alias
    res = res + ");\n"

    res = res + "void " + current_wrapper.exit_callout + "("
    if current_alias.rettype_callout != "void":
      res = res + current_alias.rettype_callout
    res = res + ");\n\n"

    # Function header (return type, name, parameters).
    res = res + current_alias.rettype_wrapper + " __wrap_"
    res = res + current_wrapper.mangled_name + "("
    count = 1
    for current_param_alias in current_alias.params_wrapper:
      if count > 1:
        res = res + ", "
      res = res + current_param_alias + " param" + str(count)
      count = count + 1
    res = res + ") {\n"

    # Call to entry callout.
    res = res + "  " + current_wrapper.entry_callout + "("
    entry_count = 1
    while entry_count < count:
      if entry_count > 1:
        res = res + ", "
      res = res + "param" + str(entry_count)
      entry_count = entry_count + 1
    res = res + ");"

    res = res + "\n\n"

    # Call to real function.
    if current_alias.rettype_wrapper != "void":
      res = res + "  " + current_alias.rettype_wrapper + " retval = "
    else:
      res = res + "  "

    res = res + "__real_" + current_wrapper.mangled_name + "("

    count = 1
    for current_param in current_wrapper.params:
      if count > 1:
        res = res + ", "
      if current_param.count("&&") > 0:
        res = res + "move(" + "param" + str(count) + ")"
      else:
        res = res + "param" + str(count)
      count = count + 1

    res = res + ");"

    res = res + "\n\n"

    # Call to exit callout.
    res = res + "  " + current_wrapper.exit_callout + "("
    if current_alias.rettype_callout != "void":
      res = res + "retval"
    res = res + ");"

    res = res + "\n\n"

    # Return
    if current_wrapper.rettype == None:
      res = res + "  return;\n"
    else:
      if current_wrapper.rettype.count("&&") > 0:
        res = res + "  return move(retval);\n"
      else:
        res = res + "  return retval;\n"

    res = res + "}\n\n\n"

  res = res + "}  // extern C\n"

  return res
