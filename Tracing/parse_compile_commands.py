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
# Parse a compile_commands.json file to find source and object files from it.
#
# Commandline parameters (order is relevant):
# argv[1]: Absolute path to the compile_commands.json file to parse.
# argv[2]: Absolute path to which the file with source file information read
#          from compile_commands.json will be generated. In that file, there is
#          one line with all absolute paths to the source files, the paths are
#          separated by one ; character. Must be accessible for read and write.
#          Directory separators must be / characters. File name must contain
#          file ending separated with . character.
# argv[3]: Absolute path to which the file with object file information read
#          from compile_commands.json will be generated. In that file, there is
#          one line with all absolute paths to the object files, the paths are
#          separated by one ; character. Must be accessible for read and write.
#          Directory separators must be / characters. File name must contain
#          file ending separated with . character.
# argv[4]: Filters to use when parsing the compile_commands.json file (different
#          filters separated by spaces). Only source files that have at least
#          one of these filters in their absolute path are taken to the output
#          files. Empty string means not filter is applied.
#
################################################################################

import sys
from os import access, R_OK, W_OK
from os.path import isfile

import json

## Evaluate command line arguments.

# argv[0] is script name.
if len(sys.argv) != 5:
  print("Wrong number of parameters passed.")
  sys.exit(1)


# Parsed file.
if isfile(sys.argv[1].strip()) and access(sys.argv[1].strip(), R_OK):
  compile_commands_path = sys.argv[1].strip()
else:
  message = "Failed to open file \"" + parsed_file
  message = message + "\" for reading."
  print(message)
  sys.exit(1)


# Source file output file.
if access(sys.argv[2].strip().rsplit("/", 1)[0], W_OK):
  source_path = sys.argv[2].strip()
else:
  message = "Failed to create/write file \"" + sys.argv[2].strip()
  message = message + "\" (second argument)."
  print(message)
  sys.exit(1)

if source_path.count("/") < 1:
  message = "Absolute path \"" + source_path + "\" (second argument) does not "
  message = message + "contain directory separator /"
  print(message)
  sys.exit(1)
if source_path.rsplit("/", 1)[1].count(".") < 1:
  message = "File path \"" + source_path + "\" (second argument) does not "
  message = message + "contain . as file ending separator in file name."
  print(message)
  sys.exit(1)


# Object file output file.
if access(sys.argv[3].strip().rsplit("/", 1)[0], W_OK):
  object_path = sys.argv[3].strip()
else:
  message = "Failed to create/write file \"" + sys.argv[3].strip()
  message = message + "\" (third argument)."
  print(message)
  sys.exit(1)

if object_path.count("/") < 1:
  message = "Absolute path \"" + object_path + "\" (third argument) does not "
  message = message + "contain directory separator /"
  print(message)
  sys.exit(1)
if object_path.rsplit("/", 1)[1].count(".") < 1:
  message = "File path \"" + object_path + "\" (third argument) does not "
  message = message + "contain . as file ending separator in file name."
  print(message)
  sys.exit(1)


# Filter strings.
if sys.argv[4].strip() == "":
  filters = []
else:
  filters = sys.argv[4].strip().split(" ")

## Parse file.
source_list = ""
object_list = ""

compile_commands_content = json.loads(open(compile_commands_path).read())

entry_counter = 1
for current_entry in compile_commands_content:
  if "directory" not in current_entry:
    message = "Error in file \"" + compile_commands_path +  "\". \"dictionary\""
    message = message + " not found in entry number " + str(entry_counter) + "."
    print(message)
    sys.exit(1)
  elif "command" not in current_entry:
    message = "Error in file \"" + compile_commands_path +  "\". \"command\" "
    message = message + "not found in entry number " + str(entry_counter) + "."
    print(message)
    sys.exit(1)
  elif "file" not in current_entry:
    message = "Error in file \"" + compile_commands_path +  "\". \"file\" not "
    message = message + "found in entry number " + str(entry_counter) + "."
    print(message)
    sys.exit(1)
  else:
    command_list = current_entry["command"].split(" ")
    if "-o" not in command_list:
      message = "Error in file \"" + compile_commands_path + "\", command \""
      message = message + current_entry["command"] + "\" of source file \""
      message = message + current_entry["file"] + "\" does not contain \"-o\"."
      print(message)
      sys.exit(1)
    elif command_list.index("-o") == (len(command_list) - 1):
      message = "Error in file \"" + compile_commands_path + "\", command \""
      message = message + current_entry["command"] + "\" of source file \""
      message = message + current_entry["file"] + "\" ends with \"-o\" so there"
      message = message + " is no object file path following the \"-o\"."
      print(message)
      sys.exit(1)
    else:
      match = False
      if len(filters) == 0:
        match = True
      else:
        for current_filter in filters:
          if current_filter in current_entry["file"]:
            match = True
            break

      if match:
        object_path_index = command_list.index("-o") + 1
        object_file_path = current_entry["directory"] + "/"
        object_file_path = object_file_path + command_list[object_path_index]

        if isfile(object_file_path):
          source_list = source_list + current_entry["file"] + ";"
          object_list = object_list + object_file_path + ";"
        else:
          message = "Warning: Object file \"" + object_file_path
          message = message + "\" for source file \"" + current_entry["file"]
          message = message + "\" does not exist. Skipping."
          print(message)

  entry_counter = entry_counter + 1


## Write outputs.

with open(source_path, "w") as source_file:
  source_file.write(source_list)

with open(object_path, "w") as object_file:
  object_file.write(object_list)

sys.exit(0)
