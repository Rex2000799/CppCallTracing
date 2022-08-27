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
# Utility functions.
################################################################################

########################################
# Splits a string into a list of strings according to top-level (w.r.t nesting)
# separation characters.
#
# parameter:
# - split_string: the string to split
# - delim (list of strings): The deliminators to split on. Will split on any of
#                   these deliminators. No deliminator may contain any of the
#                   following: ()[]{}<>
# - keep_delim (bool): Flag to select if deliminator should be kept (will be
#                      entry in output list with nothing else in there) or not.
#                      True = keep, False = discard
#
# Returns a list of strings, the entries are the split strings.
########################################
def SplitString(split_string, delim, keep_delim):
  parts = []

  # Deliminators with longer deliminators coming first (relevant if multiple
  # deliminators start with the same character sequence, will match the longest
  # one that can be matched).
  delim_ordered = sorted(delim, key=len, reverse=True)

  # Count of current round bracket () nesting.
  op_r = 0
  # Count of current square bracket [] nesting.
  op_s = 0
  # Count of current curly bracket {} nesting.
  op_c = 0
  # Count of current template bracket <> nesting.
  op_t = 0

  current_part = ""
  while split_string != "":

    scope = False
    if split_string[0] == "(":
      op_r = op_r + 1
      scope = True
    elif split_string[0] == "[":
      op_s = op_s + 1
      scope = True
    elif split_string[0] == "{":
      op_c = op_c + 1
      scope = True
    elif split_string[0] == "<":
      op_t = op_t + 1
      scope = True
    elif split_string[0] == ")":
      op_r = op_r - 1
      scope = True
    elif split_string[0] == "]":
      op_s = op_s - 1
      scope = True
    elif split_string[0] == "}":
      op_c = op_c - 1
      scope = True
    elif split_string[0] == ">":
      op_t = op_t - 1
      scope = True
    if scope:
      current_part = current_part + split_string[0]
      split_string = split_string[1:]
      continue

    split = False
    if op_r == 0 and op_s == 0 and op_c == 0 and op_t == 0:
      for current_delim in delim_ordered:
        if split_string.startswith(current_delim):
          parts.append(current_part)
          current_part = ""
          if keep_delim:
            parts.append(current_delim)
          split_string = split_string[len(current_delim):]
          split = True
    if split:
      continue

    current_part = current_part + split_string[0]
    split_string = split_string[1:]


  if current_part.strip() != "":
    parts.append(current_part.strip())

  return parts


########################################
# Gets the class name for the name of a class member function.
#
# parameter:
# - function_name (string): the full name (all namespaces) of the class member
#                           function (without parameter list and ()).
#
# Returns the name of the class (string)
########################################
def GetClassName(function_name):
  parts = SplitString(function_name, ["::"], True)
  parts = parts[:-2] # Discard function name and :: between it and class name.
  return "".join(parts)


########################################
# Enforces that the type of a function parameter complies to following rules:
# - the bare parameter type (without any const, volatile, & and *) comes first
# - only relevant const and volatile qualifiers are present (they are only)
#   relevant if they are on the non-outermost level, as in T const* (pointer to
#   const))
# - all tokens are separated by exactly one space
#
# parameter:
# - param (string): the function parameter type to normalize
#
# Returns the name normalized parameter (string).
########################################
def NormalizeParameterType(param):
  cleaned = param.replace("\t", " ").replace("\r", " ").replace("\n", " ")

  tokens = SplitString(cleaned, ["&&", "&", "*", " "], True)

  # Remove isolated spaces and empty strings.
  tokens = [item for item in tokens if ((item != " ") and (item != ""))]

  qualifier_list = ["const", "volatile", "&", "*", "&&"]

  types = [] # may be multiple strings here, e.g. in case of "struct s const *"
  qualifiers = []

  for current_token in tokens:
    if current_token in qualifier_list:
      qualifiers.append(current_token)
    else:
      types.append(current_token)

  potential_irrelevant_qualifiers = ["const", "volatile"]

  # const and volatile are not relevant for parameter lists when they are in the
  # outermost level of the type. Refer to § 13.1 of the standard for details.
  # Due to the ordering done before, "outermost level" translates to
  # "last in the list of qualifiers". So const and volatile are removed from the
  # end of the list.
  while (len(qualifiers) > 0) and (qualifiers[-1] in potential_irrelevant_qualifiers):
    qualifiers = qualifiers[:-1]

  # Make one large string from lists of strings with spaces between the strings.
  return " ".join(types + qualifiers).strip()

########################################
# Merges multiple dictionaries with vtable information to one and does
# consistency checks.
#
# input parameters:
# - all_dicts (list of (dict(string -> dict(string -> VtableInfo)))):
#      The dictionaries to merge. The string of the outer dict is the full path
#      of the file the information comes from. The string in the inner dict is
#      the name of the class.
#
# Returns the merged dict (dict(string -> VtableInfo)) where the string is the
# name of the class). If the consistency check fails, returns None prints an
# error message.
#
########################################
def MergeFileInformation(all_dicts):
  # dict(string -> [VtableInfo, string])
  # key is class name, string in value is file the information comes from
  interm_result = {}

  for current_file in all_dicts:
    for current_class in all_dicts[current_file]:
      if current_class in interm_result:
        current_mangled_name = all_dicts[current_file][current_class].mangled_name
        stored_mangled_name = interm_result[current_class][0].mangled_name

        current_content = all_dicts[current_file][current_class].entries
        stored_content = interm_result[current_class][0].entries

        message = "Inconsistent vtable information found in different files. "
        message = message + "First file is \"" + interm_result[current_class][1]
        message = message + "\". Second file is \"" + current_file + "\". Class"
        message = message + " is: \"" + current_class + "\". "
        if current_mangled_name != stored_mangled_name:
          message = message + "Mangled names of vtables do not match. First "
          message = message + "name is \"" + stored_mangled_name + "\", second "
          message = message + "name is \"" + current_mangled_name + "\"."
          print(message)
          return None
        elif current_content != stored_content:
          message = message + "Vtable contents do not match. Content of first "
          message = message + "vtable is \"" + str(stored_content) + "\", "
          message = message + "content of second vtable is \""
          message = message + str(current_content) + "\"."
          print(message)
          return None
        else:
          # Both vtables are the same. Consistency check passed.
          pass
      else:
        interm_result[current_class] = [all_dicts[current_file][current_class], current_file]

  # dict(string -> VtableInfo)
  result = {}
  for current_class in interm_result:
    result[current_class] = interm_result[current_class][0]

  return result
