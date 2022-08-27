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
# Generates wrappers for tracing C++ function calls.
#
# Commandline parameters (order is relevant):
# argv[1]: Absolute path to the file with the list of functions to trace. This
#          file contains information about traced functions in yaml format. Must
#          be accessible for read.
# argv[2]: Absolute path to which the file with the callout declarations will
#          be generated. Must be accessible for read and write. Directory
#          separators must be / characters. File name must contain file ending
#          separated with . character.
# argv[3]: Absolute path to which the file with the callout definitions will
#          be generated. Must be accessible for read and write. Directory
#          separators must be / characters. File name must contain file ending
#          separated with . character.
# argv[4]: Include path to use in the callout definition file to include the
#          callout declaration file.
#
################################################################################

import sys
from os import access, R_OK, W_OK
from os.path import isfile

import datetime
import shutil

from parsers.parser_function_list import ParseFunctionList
from parsers.generated_file_parser import ParseGeneratedFile
from parsers.function_info import CalloutInfo
from parsers.user_code_info import UserCodeInfo

from generators.utils import GenerateCalloutNames

from generators.callout_declaration_generator import GenerateCalloutDeclarations
from generators.callout_definition_generator import GenerateCalloutDefinitions


## Evaluate command line arguments.

# argv[0] is script name.
if len(sys.argv) != 5:
  print("Wrong number of parameters passed.")
  sys.exit(1)


# List of ConfigInfo
traced_function_list = ParseFunctionList(sys.argv[1].strip())

if traced_function_list == None:
  # Error message was already printed by ParseFunctionList()
  sys.exit(1)


if access(sys.argv[2].strip().rsplit("/", 1)[0], W_OK):
  header_path = sys.argv[2].strip()
else:
  message = "Failed to create/write file \"" + sys.argv[2].strip()
  message = message + "\" (second argument)."
  print(message)
  sys.exit(1)

if header_path.count("/") < 1:
  message = "Absolute path \"" + header_path + "\" (second argument) does not "
  message = message + "contain directory separator /"
  print(message)
  sys.exit(1)
if header_path.rsplit("/", 1)[1].count(".") < 1:
  message = "File path \"" + header_path + "\" (second argument) does not "
  message = message + "contain . as file ending separator in file name."
  print(message)
  sys.exit(1)


parse_user_source = False

if isfile(sys.argv[3].strip()):
  if access(sys.argv[3].strip(), R_OK):
    parse_user_source = True
  else:
    message = "Failed to read file \"" + sys.argv[3].strip()
    message = message + "\" (third argument)."
    print(message)
    sys.exit(1)

if access(sys.argv[3].strip().rsplit("/", 1)[0], W_OK):
  source_path = sys.argv[3].strip()
else:
  message = "Failed to create/write file \"" + sys.argv[3].strip()
  message = message + "\" (third argument)."
  print(message)
  sys.exit(1)

if source_path.count("/") < 1:
  message = "Absolute path \"" + source_path + "\" (third argument) does not "
  message = message + "contain directory separator /"
  print(message)
  sys.exit(1)
if source_path.rsplit("/", 1)[1].count(".") < 1:
  message = "File path \"" + source_path + "\" (third argument) does not "
  message = message + "contain . as file ending separator in file name."
  print(message)
  sys.exit(1)


include_path = sys.argv[4]


## Compute callouts from traced functions.

# List of CalloutInfo objects.
callout_list = []

for current_function in traced_function_list:
  current_callout = GenerateCalloutNames(current_function.name, current_function.parameters)
  current_callout.rettype = current_function.rettype
  current_callout.level = current_function.level
  current_callout.include = current_function.include
  callout_list.append(current_callout)


## Parse user code if required.

# Content of the user source file that is to be taken into the generated source
# file. None if no content to be taken. Instance of UserCodeInfo
user_source_contents = None

if parse_user_source:
  user_source_contents = ParseGeneratedFile(source_path)
  if user_source_contents == None:
    # Error message already printed by ParseGeneratedFile()
    sys.exit(1)


time = datetime.datetime.now()
backup_name_time_component = str(time.year) + "_" + str(time.month) + "_"
backup_name_time_component = backup_name_time_component + str(time.day) + "_"
backup_name_time_component = backup_name_time_component + str(time.hour) + "_"
backup_name_time_component = backup_name_time_component + str(time.minute) + "_"
backup_name_time_component = backup_name_time_component + str(time.second)


## Generate and write callout declarations.

header_contents = GenerateCalloutDeclarations(callout_list)

with open(header_path, "w") as header_file:
  header_file.write(header_contents)


## Generate and write callout definitions. Backup old file if present.

if parse_user_source:
  source_before_ending = source_path.rsplit(".", 1)[0]
  source_ending = source_path.rsplit(".", 1)[1]
  source_backup_path = source_before_ending + "_backup_"
  source_backup_path = source_backup_path + backup_name_time_component + "."
  source_backup_path = source_backup_path + source_ending
  shutil.copy2(source_path, source_backup_path)

source_contents = GenerateCalloutDefinitions(callout_list, user_source_contents, include_path)

with open(source_path, "w") as source_file:
  source_file.write(source_contents)




sys.exit(0)
