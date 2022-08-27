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
# Contains function ParseFunctionList() that can be used to parse information
# about functions.
#
# Inputs expected by ParseFunctionList():
# - Absolute path to the file to parse (string). Must be accessible for read.
#
# ParseFunctionList() returns a list of ConfigInfo objects.
#
# In case of error, None is returned and an error message is printed.
################################################################################

from os import access, R_OK, W_OK
from os.path import isfile

from parsers.function_info import ConfigInfo

import yaml

def ParseFunctionList(parsed_file):
  result = []

  if isfile(parsed_file) and access(parsed_file, R_OK):
    with open(parsed_file, 'r') as functions_file:
      try:
        function_list = yaml.safe_load(functions_file)
      except yaml.YAMLError as ex:
        message = "File \"" + parsed_file
        message = message + "\" does not contain valid yaml format. Details: "
        message = message + str(ex)
        print(message)
        return None

    message = "File \"" + parsed_file + "\" is invaid, following errors"
    message = message + " were dected:\n"
    is_valid = True

    if type(function_list) is not list:
      message = message + "- Top-level is not a list of items. Check indent and"
      message = message + " - bullet points.\n"
      is_valid = False
    else:
      counter_function = 1
      for current_function in function_list:
        if type(current_function) is not dict:
          message = message + "- Entry #" + str(counter_function) + " is not a"
          message = message + " list of keys on the same level.\n"
          is_valid = False
        elif "function" not in current_function:
          message = message + "- Entry #" + str(counter_function) + " lacks key"
          message = message + " \"function\".\n"
          is_valid = False
        elif type(current_function["function"]) is not str:
          message = message + "- Value of key \"function\" for entry #"
          message = message + str(counter_function) + " is not a string.\n"
          is_valid = False
        elif "return" not in current_function:
          message = message + "- Entry #" + str(counter_function) + " lacks key"
          message = message + " \"return\".\n"
          is_valid = False
        elif type(current_function["return"]) is not str:
          message = message + "- Value of key \"return\" for entry #"
          message = message + str(counter_function) + " is not a string.\n"
          is_valid = False
        elif "level" not in current_function:
          message = message + "- Entry #" + str(counter_function) + " lacks key"
          message = message + " \"level\".\n"
          is_valid = False
        elif type(current_function["level"]) is not str:
          message = message + "- Value of key \"level\" for entry #"
          message = message + str(counter_function) + " is not a string.\n"
          is_valid = False
        elif current_function["level"] not in ["free", "member", "const"]:
          message = message + "- Value of key \"level\" for entry #"
          message = message + str(counter_function) + " is not valid. Options "
          message = message + " are \"free\", \"member\" and \"const\".\n"
          is_valid = False
        elif "parameters" not in current_function:
          message = message + "- Entry #" + str(counter_function) + " lacks key"
          message = message + " \"parameters\".\n"
          is_valid = False
        elif (current_function["parameters"] != None) and (type(current_function["parameters"]) is not list):
          message = message + "- Value of key \"parameters\" for entry #"
          message = message + str(counter_function) + " is not a list. "
          message = message + "Check indent and - bullet points.\n"
          is_valid = False
        elif "include" not in current_function:
          message = message + "- Entry #" + str(counter_function) + " lacks key"
          message = message + " \"include\".\n"
        elif type(current_function["include"]) is not str:
          message = message + "- Value of key \"include\" for entry #"
          message = message + str(counter_function) + " is not a string.\n"
        elif len(current_function) != 5:
          message = message + "- Entry #" + str(counter_function) + " has too"
          message = message + " many keys.\n"
          is_valid = False
        else:
          info = ConfigInfo(current_function["function"].strip(), current_function["return"].strip(), current_function["level"], current_function["include"].strip())
          if current_function["parameters"] == None:
            # No parameters for this function.
            info.parameters = []
          else:
            counter_param = 1
            for current_param in current_function["parameters"]:
              if type(current_param) is not str:
                message = message + "- Parameter #" + str(counter_param) + " "
                message = message + "for entry #" + str(counter_function) + " "
                message = message + "is not a string.\n"
                is_valid = False
              else:
                info.parameters.append(current_param.strip())
              counter_param = counter_param + 1
          result.append(info)
        counter_function = counter_function + 1

    if not is_valid:
      print(message)
      return None

  else:
    message = "Failed to open file \"" + parsed_file
    message = message + "\" for reading."
    print(message)
    return None

  return result
