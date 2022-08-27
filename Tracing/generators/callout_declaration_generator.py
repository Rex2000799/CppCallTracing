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
# Contains function GenerateCalloutDeclarations() that generates declrations
# for callouts for traced functions.
#
# Parameters:
# - callout_list (list of CalloutInfo objects): Information about the callouts
#                                               to generate.
#
# Retruns a string that contains the generated file contents with declarations.
#
################################################################################

from generators.utils import GenerateIncludes


def GenerateCalloutDeclarations(callout_list):
  res = "// ATTENTION: GENERATED FILE, DO NOT MODIFY.\n"

  res = res + "\n\n"
  res = res + "#ifndef TRACING_GENERATED_CALLOUTS_H_\n"
  res = res + "#define TRACING_GENERATED_CALLOUTS_H_\n"
  res = res + "\n\n"

  res = res + GenerateIncludes(callout_list)

  res = res + "\n\n"
  res = res + "namespace tracing {\n"
  res = res + "\n\n"

  for current_callout in callout_list:
    entry_decl = "void " + current_callout.entry_name.replace("tracing::", "")
    entry_decl = entry_decl + "(" + current_callout.GetEntryParameters()
    entry_decl = entry_decl + ") noexcept;"

    exit_decl = "void " + current_callout.exit_name.replace("tracing::", "")
    exit_decl = exit_decl + "(" + current_callout.GetExitParameters()
    exit_decl = exit_decl + ") noexcept;"

    res = res + entry_decl + "\n" + exit_decl + "\n\n"

  res = res + "\n\n"
  res = res + "}  // namespace tracing\n"
  res = res + "\n"
  res = res + "#endif // TRACING_GENERATED_CALLOUTS_H_\n"

  return res
