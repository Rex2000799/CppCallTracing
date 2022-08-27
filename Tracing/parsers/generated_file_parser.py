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
# Contains function ParseGeneratedFile() that can be used to parse user code
# from generated files.
#
# Inputs expected by ParseGeneratedFile():
# - Absolute path to the file to parse (string). Must be accessible for read.
#
# ParseGeneratedFile() returns a UserCodeInfo object.
#
# In case of error, None is returned and an error message is printed.
################################################################################

from os import access, R_OK, W_OK
from os.path import isfile

from parsers.user_code_info import UserCodeInfo


def ParseGeneratedFile(parsed_file):
  result = UserCodeInfo()

  if isfile(parsed_file) and access(parsed_file, R_OK):
    with open(parsed_file, 'r') as file:
      start_marker = "// USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT."
      id_marker = "// AREA ID:"
      end_marker = "// USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT."
      comment_border = "// -----------------------------------------------------------"
      # State machine state. Possible states:
      # - searching: searching for start of user code area
      # - starting: found start of user code area, searching user code area ID
      # - skipping: skipping one line
      # - parsing: parsing user code area
      #
      # state machine:
      # @startuml
      # 
      #   state searching
      #   state starting
      #   state parsing
      # 
      #   searching --> starting : start_marker in line
      #   starting --> skipping : "id_marker in line, store ID
      #   skipping --> parsing : one line
      #   parsing --> parsing : else, store content
      #   parsing --> searching : end_marker in line
      #
      # @enduml
      state_searching = "searching"
      state_starting = "starting"
      state_skipping = "skipping"
      state_parsing = "parsing"
      state = state_searching

      area_id = ""
      area_content = []

      line_count = 1
      for current_line in file:
        if state == state_searching:
          if current_line.strip().startswith(start_marker):
            state = state_starting
        elif state == state_starting:
          if current_line.strip().startswith(id_marker):
            area_id = current_line.split(id_marker)[1].strip()
            state = state_skipping
          else:
            message = "Error while parsing file \"" + parsed_file + "\", "
            message = message + "encountered user code area start marker "
            message = message + "without area ID in Line " + str(line_count)
            print(message)
            return None
        elif state == state_skipping:
          if current_line.strip().startswith(comment_border):
            state = state_parsing
          else:
            message = "Error while parsing file \"" + parsed_file + "\", "
            message = message + "encountered user code area start marker "
            message = message + "without comment border ( - characters) in "
            message = message + "line " + str(line_count)
            print(message)
            return None
        elif state == state_parsing:
          if current_line.strip().startswith(end_marker):
            if area_content[-1].strip().startswith(comment_border):
              area_content = area_content[0:-1] # Ignore comment border of end marker comment.
              if area_id == "INCLUDES":
                result.AddIncludeUserCode(area_content)
              else:
                result.AddCalloutUserCode(area_id, area_content)
              area_id = ""
              area_content = []
              state = state_searching
            else:
              message = "Error while parsing file \"" + parsed_file + "\", "
              message = message + "encountered user code area end marker "
              message = message + "without comment border ( - characters) in "
              message = message + "line " + str(line_count)
              print(message)
              return None
          else:
            area_content.append(current_line)
        else:
          print("Invalid state \"" + state + "\" encountered.")
          return None

        line_count = line_count + 1

      if state != "searching":
        message = "Error while parsing file \"" + parsed_file + "\", "
        message = message + "encountered file end while in user code area."
        print(message)
        return None

  else:
    message = "Failed to open file \"" + parsed_file
    message = message + "\" for reading."
    print(message)
    return None

  return result
