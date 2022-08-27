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
# Support functions for code generation.
#
################################################################################

from parsers.function_info import CalloutInfo
from parsers.utils import NormalizeParameterType

########################################
# Generates the name of a callout function from the signature of the traced
# function.
#
# Input parameters:
# - name (string): The name of the traced function without parameters or
#                  (). Full namespaces, no leading ::
# - params (list of strings): The parameters of the traced function.
#
# Returns a populated CalloutInfo instance that has following members populated:
# - prod_name
# - params
# - entry_name
# - exit_name
########################################
def GenerateCalloutNames(name, params):
  normalized_parameters = []
  for current_param in params:
    normalized_parameters.append(NormalizeParameterType(current_param))

  target_name = name.strip() + "("
  first = True
  for current_param in normalized_parameters:
    if not first:
      target_name = target_name + ", "
    else:
      first = False
    target_name = target_name + current_param
  target_name = target_name + ")"

  # Note: avoided _ at the beginning or end to avoid creating double _
  target_name = target_name.replace(" ", "")

  # "Longer" operators (with two or three characters) need to come first to
  # avoid partially replacing an operator.
  target_name = target_name.replace("operator++", "op_i") # "operator increment"
  target_name = target_name.replace("operator--", "op_d") # "operator decrement"
  target_name = target_name.replace("operator+=", "op_pla") # "operator plus assignment"
  target_name = target_name.replace("operator-=", "op_mia") # "operator minus assignment"
  target_name = target_name.replace("operator*=", "op_mua") # "operator multiplication assignment"
  target_name = target_name.replace("operator/=", "op_dia") # "operator division assignment"
  target_name = target_name.replace("operator%=", "op_moa") # "operator modulo assignment"
  target_name = target_name.replace("operator^=", "op_xa") # "operator xor assignment"
  target_name = target_name.replace("operator&=", "op_aa") # "operator and assignment"
  target_name = target_name.replace("operator|=", "op_oa") # "operator or assignment"
  target_name = target_name.replace("operator>>=", "op_sra") # "operator shift right assignment"
  target_name = target_name.replace("operator<<=", "op_sla") # "operator shift left assignment"
  target_name = target_name.replace("operator!=", "op_ne") # "operator not equal"
  target_name = target_name.replace("operator<=", "op_le") # "operator less or equal"
  target_name = target_name.replace("operator>=", "op_ge") # "operator greater or equal"
  target_name = target_name.replace("operator==", "op_eq") # "operator equal"
  target_name = target_name.replace("operator>>", "op_sr") # "operator shift right"
  target_name = target_name.replace("operator<<", "op_sl") # "operator shift left"
  target_name = target_name.replace("operator->", "op_dr") # "operator dereference"
  target_name = target_name.replace("operator()", "op_ca") # "operator call"
  target_name = target_name.replace("operator[]", "op_ar") # "operator array"
  target_name = target_name.replace("operator&&", "op_la") # "operator logical and"
  target_name = target_name.replace("operator||", "op_lo") # "operator logical or"
  target_name = target_name.replace("operator!", "op_ln") # "operator logical negation"
  target_name = target_name.replace("operator+", "op_pl") # "operator plus"
  target_name = target_name.replace("operator-", "op_mi") # "operator minus"
  target_name = target_name.replace("operator*", "op_mu") # "operator multiplication"
  target_name = target_name.replace("operator/", "op_di") # "operator division"
  target_name = target_name.replace("operator%", "op_mo") # "operator modulo"
  target_name = target_name.replace("operator^", "op_bx") # "operator bitwise xor"
  target_name = target_name.replace("operator&", "op_ba") # "operator bitwise and"
  target_name = target_name.replace("operator|", "op_bo") # "operator bitwise or"
  target_name = target_name.replace("operator~", "op_bn") # "operator bitwise negation"
  target_name = target_name.replace("operator=", "op_as") # "operator assignment"
  target_name = target_name.replace("operator<", "op_lt") # "operator less than"
  target_name = target_name.replace("operator>", "op_gt") # "operator greater than"
  target_name = target_name.replace("operator,", "op_co") # "operator comma"

  target_name = target_name.replace("::", "c_o_l") # "colon"
  target_name = target_name.replace(",", "c_o_m") # "comma"
  target_name = target_name.replace("(", "r_o") # "round open"
  target_name = target_name.replace(")", "r_c") # "round close"
  target_name = target_name.replace("[", "s_o") # "square open"
  target_name = target_name.replace("]", "s_c") # "square close"
  target_name = target_name.replace("{", "c_o") # "curly open"
  target_name = target_name.replace("}", "c_c") # "curly close"
  target_name = target_name.replace("<", "t_o") # "template open"
  target_name = target_name.replace(">", "t_c") # "template close"
  target_name = target_name.replace("*", "ptr") # "pointer"
  target_name = target_name.replace("&", "ref") # "reference"

  entry_name = "tracing::entry" + target_name
  exit_name = "tracing::exit" + target_name

  return CalloutInfo(name.strip(), normalized_parameters, entry_name, exit_name)

########################################
# Generates code for header include from configuration information about C++
# functions.
#
# Input parameters:
# - config (list of CalloutInfo or WrapperInfo objects): The configuration
#                                                        information.
#
# Returns a string with the includes that can be used for code generation.
########################################
def GenerateIncludes(config):
  res = ""
  unique_includes = []
  for current_config in config:
    if current_config.include not in unique_includes:
      unique_includes.append(current_config.include)
  for current_include in unique_includes:
    res = res + current_include + "\n"
  return res

########################################
# Generates code for a singleton that will call a function on construction. The
# singleton is set up as global variable so construction will take place before
# main() is entered.
#
# Input parameters:
# - callout (string): The name of the function to call.
#
# Returns a string with the singleton code that can be used for code generation.
########################################
def GenerateCallbackSingleton(callout):
  res =       "class CallbackSingleton final {\n"
  res = res + " public:\n"
  res = res + "  CallbackSingleton() {\n"
  res = res + "    " + callout + "();\n"
  res = res + "  }\n"
  res = res + "};\n"
  res = res + "\n\n"
  res = res + "CallbackSingleton callback_singleton_instance{};\n"

  return res
