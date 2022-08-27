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
# Support classes for storing information about a C++ function.
#
################################################################################

from parsers.utils import SplitString
from parsers.utils import GetClassName


########################################
# Represents information about one C++ function read from a binary.
#
# member variables:
# - mangled_name (string): mangled name of the function
# - params (list of strings): the types of the parameters of the function in the
#                             order they occur in code, each entry one parameter
########################################
class BinaryInfo:
  ######################################
  # Creates an instance.
  #
  # parameters:
  # - mangled_name (string): the mangled name of the function
  # - parameters (list of strings): the parameters of the function - basically
  #                                 the content between the () of the function
  #                                 signature
  ######################################
  def __init__(self, mangled_name, parameters):
    self.mangled_name = mangled_name
    self.params = SplitString(parameters, [","], False)


########################################
# Represents information about the callouts for one C++ function.
#
# member variables:
# - prod_name (string): unmangled name of the traced function this callout
#                       belongs to
# - params (list strings): the types of the parameters of the traced function in
#                          the order they occur in code, each entry one
#                          parameter
# - rettype (string): The return type of the function.
# - level (string): kind of function, one of "free" (free or static member
#                   function), "member" (non-static, non-const member function)
#                   or "const" (const member function)
# - entry_name (string): unmangled name of the entry callout, full namespace, no
#                        leading ::
# - exit_name (string): unmangled name of the exit callout, full namespace, no
#                       leading ::
# - include (string): Include for the header with declaration of the function
#                     this callout is for.
########################################
class CalloutInfo:
  ######################################
  # Creates an instance.
  #
  # parameters:
  # - prod_name (string): the unmangled name of the function this callout
  #                       belongs to
  # - parameters (list of strings): the parameters of the function, one string
  #                                 per parameter, same order as in code/config.
  # - entry_name (string): the unmangled name of the entry callout, full
  #                        namespace, no leading ::
  # - exit_name (string): the unmangled name of the exit callout, full
  #                       namespace, no leading ::
  ######################################
  def __init__(self, prod_name, parameters, entry_name, exit_name):
    self.prod_name = prod_name
    self.params = parameters
    self.rettype = None
    self.level = None
    self.entry_name = entry_name
    self.exit_name = exit_name
    self.include = None

  ######################################
  # Outputs the parameters for the entry callout as one string suitable to
  # generate callout code from it.
  #
  # Also handles the case of class member functions (that get additional
  # parameter for the this pointer).
  #
  # Returns a string with the parameters.
  ######################################
  def GetEntryParameters(self):
    assert self.level != None # Assert initialization.

    if self.level == "const":
      used_params = [GetClassName(self.prod_name) + " const *"]
    elif self.level == "member":
      used_params = [GetClassName(self.prod_name) + " *"]
    else: # level == "free"
      used_params = []

    # Make && to & so calling the callout does not move away a move-only
    # parameter.
    for current_param in self.params:
      # It is assured that && has a space in front of it by
      # NormalizeParameterType.
      used_params.append(current_param.replace(" &&", " &"))

    result = ""
    first = True
    param_count = 0
    for current_param in used_params:
      if not first:
        result = result + ", "
      else:
        first = False
      result = result + current_param + " param" + str(param_count)
      param_count = param_count + 1

    return result

  ######################################
  # Outputs a cast to void of the parameters for the entry callout as one string
  # suitable to generate callout code from it.
  #
  # Also handles the case of class member functions (that get additional
  # parameter for the this pointer).
  #
  # Returns a string with the parameters casted to void.
  ######################################
  def GetEntryParameterCastVoid(self):
    assert self.rettype != None # Assert initialization.

    number_of_params = len(self.params)

    if (self.level == "const") or (self.level == "member"):
      number_of_params = number_of_params + 1

    result = ""

    for i in range(0, number_of_params):
      result = result + "  static_cast<void>(param" + str(i) + ");\n"
    
    return result


  ######################################
  # Outputs the parameters for the exit callout as one string suitable to
  # generate code from it.
  #
  # Returns a string with the parameters.
  ######################################
  def GetExitParameters(self):
    assert self.rettype != None # Assert initialization.

    result = ""
    if self.rettype != "void":
      # Make && to & so calling the callout does not move away a move-only
      # return value.
      # It is assured that && has a space in front of it by
      # NormalizeParameterType.
      result = self.rettype.replace(" &&", " &") + " retval"

    return result


  ######################################
  # Outputs the parameters for the exit callout casted to void as one string
  # suitable to generate code from it.
  #
  # Returns a string with the parameters casted to void.
  ######################################
  def GetExitParameterCastVoid(self):
    assert self.rettype != None # Assert initialization.

    result = ""

    if self.rettype != "void":
      result = "  static_cast<void>(retval);\n"
    
    return result


  ######################################
  # Outputs the signature of the production code function for this callout.
  #
  # Returns a string with the signature.
  ######################################
  def GetProductionSignature(self):
    assert self.rettype != None # Assert initialization.
    signature = self.rettype + " " + self.prod_name + "("
    first = True
    for current_param in self.params:
      if first:
        first = False
      else:
        signature = signature + ", "
      signature = signature + current_param
    signature = signature + ")"
    return signature

########################################
# Represents information about one C++ function read from a configuration file.
#
# member variables:
# - name (string): unmangled name of the function.
# - rettype (string): The return type of the function.
# - level (string): kind of function, one of "free" (free or static member
#                   function), "member" (non-static, non-const member function)
#                   or "const" (const member function)
# - parameters (list of strings): Types of parameters, each entry corresponds
#                                 to the type of one parameter. Order is the
#                                 same as in the config (should be the same
#                                 as in the code).
# - include (string): Include for the header with declaration of the function.
########################################
class ConfigInfo:
  ######################################
  # Creates an instance.
  #
  # parameters:
  # - name (string): The unmangled name of the function.
  # - rettype (string): The return type of the function.
  # - level (string): The kind of function. See class description for details.
  # - include (string): Include for the header with declaration if the function.
  ######################################
  def __init__(self, name, rettype, level, include):
    self.name = name
    self.rettype = rettype
    self.level = level
    self.parameters = []
    self.include = include
