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
# Contains function ParseBinaries() that allows to get a mapping between mangled
# and unmangled names of functions from a list of binary files.
#
# Inputs expected by ParseBinaries():
# - A list of absolute paths of binary files to process (list of strings). These
#   files must be accessible for read.
# - A list of relevant function names (list of strings).
#   - Full namespaces (no leading ::) with class names if applicable.
#   - No () after the function name.
#   - No return type.
#   - For overloads, all overloads will be matched. For templates, all template
#     instances will be matched.
# - The absolute path to a working directory where temporary files can be placed
#   (string). Files will be removed before this function ends. Directory must
#   be accessible for write.
#
# ParseBinaries() returns a dictionary that maps unmangled function name
# (string) to a list of BinaryInfo objects. If a function could not be found,
# it maps to None. If an error occurred, None is returned and an error message
# is printed.
#
################################################################################

import os
import random
import itertools
from parsers.function_info import BinaryInfo

########################################
# Parses nm output for one binary file.
#
# parameters:
# - content_mangled (list of strings): nm output for binary file to process, one
#   entry in this list corresponds to one output line of nm 
# - content_unmangled (list of strings): nm output for binary file to process,
#   one entry in this list corresponds to one output line of nm 
# - funcinfolist (dict string -> list of BinaryInfo): Currently available
#   information about functions.
#
# returns the updated function information list.
########################################
def ParseBinary(content_mangled, content_unmangled, funcinfolist):
  for (cur_mangled, cur_unmangled) in zip(content_mangled, content_unmangled):
    for current_function in funcinfolist:
      if (current_function in cur_unmangled) and (cur_unmangled.split(current_function, 1)[1].strip().startswith("(")):
        # Everything before first space.
        mangled_name = cur_mangled.split(" ")[0]

        has_symbol_type = len(cur_mangled.split(" ")) > 1
        in_text_section = has_symbol_type and (cur_mangled.split(" ")[1].startswith("T") or cur_mangled.split(" ")[1].startswith("t"))
        is_weak_symbol = has_symbol_type and (cur_mangled.split(" ")[1].startswith("W") or cur_mangled.split(" ")[1].startswith("w"))
        is_weak_object = has_symbol_type and (cur_mangled.split(" ")[1].startswith("V") or cur_mangled.split(" ")[1].startswith("v"))

        # Filter out all symbols that are not in text section and not weak as
        # code and virtual tables should be in these categories.
        if in_text_section or is_weak_symbol or is_weak_object:
          # Remove everything after closing ), remove function name and
          # everything in front of it.
          interm = cur_unmangled.rsplit(")", 1)[0].split(current_function, 1)[1]
          params = interm[1:] # Remove first character - opening (

          found = False
          for current_info in funcinfolist[current_function]:
            if mangled_name == current_info.mangled_name:
              found = True
              break

          if not found:
            info = BinaryInfo(mangled_name, params)
            funcinfolist[current_function].append(info)

  return funcinfolist

########################################
# Main function of this file. Refer to start of file for details.
########################################
def ParseBinaries(binary_list, function_list, working_directory):
  while working_directory.endswith("/"):
    working_directory = working_directory[0:-1]

  file_unique_token = str(random.randint(0, 65000))
  file_mangled = working_directory + "/nm_output_file_mangled_"
  file_mangled = file_mangled + file_unique_token + ".txt"
  file_unmangled = working_directory + "/nm_output_file_unmangled_"
  file_unmangled = file_unmangled + file_unique_token + ".txt"

  # Maps unmangled function name (string) to function information (list of
  # BinaryInfo instances).
  function_map = {}

  for current_function in function_list:
    function_map[current_function] = []

  for current_binary in binary_list:
    parse_command_mangled = "nm \"" + current_binary + "\" -P -n > \""
    parse_command_mangled = parse_command_mangled + file_mangled + "\""
    parse_command_unmangled = "nm \"" + current_binary + "\" -C -P -n > \""
    parse_command_unmangled = parse_command_unmangled + file_unmangled + "\""

    if os.system(parse_command_mangled) != 0:
      message = "Command \"" + parse_command_mangled + "\" failed."
      print(message)
      return None
    elif os.system(parse_command_unmangled) != 0:
      message = "Command \"" + parse_command_unmangled + "\" failed."
      print(message)
      os.remove(file_mangled)
      return None
    else:
      content_mangled = []
      content_unmangled = []
      with open(file_mangled, 'r') as file:
        for current_line in file:
          content_mangled.append(current_line.strip())
      with open(file_unmangled, 'r') as file:
        for current_line in file:
          content_unmangled.append(current_line.strip())
      function_map = ParseBinary(content_mangled, content_unmangled, function_map)

      os.remove(file_mangled)
      os.remove(file_unmangled)

  for current_function in function_map:
    if function_map[current_function] == []:
      function_map[current_function] = None

  return function_map
