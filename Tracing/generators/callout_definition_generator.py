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
# Contains function GenerateCalloutDefinitions() that generates definitions
# of callouts for traced functions.
#
# Parameters:
# - callout_list (list of CalloutInfo objects): Information about the callouts
#                                               to generate.
# - user_code (None or UserCodeInfo object): Information about user code to add
#                                            to generated callouts.
# - include (string): Include to use to include callout declarations.
#
# Returns a string that contains the generated file contents with definitions.
#
################################################################################

def GenerateCalloutDefinitions(callout_list, user_code, include):
  res = "// ATTENTION: GENERATED FILE, ONLY MODIFY EXPLICITLY MARKED PARTS.\n\n"
  res = res + "// Disable clang format to avoid that it breaks the user\n"
  res = res + "// change area marker comments.\n"
  res = res + "// clang-format off\n\n"

  res = res + "\n\n"
  res = res + "#include \"" + include + "\"\n"

  res = res + "\n\n"
  res = res + "// Insert required includes in following area. These includes\n"
  res = res + "// will be preserved for new generations of this file.\n"
  res = res + "\n"

  res = res + "// -----------------------------------------------------------\n"
  res = res + "// USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.\n"
  res = res + "// AREA ID: INCLUDES\n"
  res = res + "// -----------------------------------------------------------\n"

  if user_code != None and user_code.include_content != None:
    for current_user_include in user_code.include_content:
      # Do NOT strip whitespace here to preserve user format
      res = res + current_user_include
      if not current_user_include.endswith("\n"):
        # Ensure there is a linebreak at the end of each line so each #include
        # is on a separate line.
        res = res + "\n"

  res = res + "// -----------------------------------------------------------\n"
  res = res + "// USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  \n"
  res = res + "// -----------------------------------------------------------\n"

  res = res + "\n\n"
  res = res + "namespace tracing {\n"
  res = res + "\n\n"

  for current_callout in callout_list:
    res = res + "// Entry callout for function "
    res = res + current_callout.GetProductionSignature() + "\n"
  
    res = res + "void " + current_callout.entry_name.replace("tracing::", "")
    res = res + "(" + current_callout.GetEntryParameters()
    res = res + ") noexcept {\n"

    res = res + current_callout.GetEntryParameterCastVoid()

    res = res + "  // -----------------------------------------------------------\n"
    res = res + "  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  \n"
    res = res + "  // AREA ID: " + current_callout.entry_name + "\n"
    res = res + "  // -----------------------------------------------------------\n"

    if user_code != None:
      current_user_code = user_code.GetCalloutUserCode(current_callout.entry_name)
      if current_user_code != None:
        for current_user_line in current_user_code:
          # Do NOT strip whitespace here to preserve user format
          res = res + current_user_line
          if not current_user_line.endswith("\n"):
            res = res + "\n"

    res = res + "  // -----------------------------------------------------------\n"
    res = res + "  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  \n"
    res = res + "  // -----------------------------------------------------------\n"

    res = res + "}\n\n"


    res = res + "// Exit callout for function "
    res = res + current_callout.GetProductionSignature() + "\n"

    res = res + "void " + current_callout.exit_name.replace("tracing::", "")
    res = res + "(" + current_callout.GetExitParameters()
    res = res + ") noexcept {\n"

    res = res + current_callout.GetExitParameterCastVoid()

    res = res + "  // -----------------------------------------------------------\n"
    res = res + "  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  \n"
    res = res + "  // AREA ID: " + current_callout.exit_name + "\n"
    res = res + "  // -----------------------------------------------------------\n"

    if user_code != None:
      current_user_code = user_code.GetCalloutUserCode(current_callout.exit_name)
      if current_user_code != None:
        for current_user_line in current_user_code:
          # Do NOT strip whitespace here to preserve user format
          res = res + current_user_line
          if not current_user_line.endswith("\n"):
            res = res + "\n"

    res = res + "  // -----------------------------------------------------------\n"
    res = res + "  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  \n"
    res = res + "  // -----------------------------------------------------------\n"

    res = res + "}\n\n"

  res = res + "\n\n"
  res = res + "}  // namespace tracing\n"

  res = res + "// clang-format on\n"

  return res
