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
# Contains function ParseStructureFilesGcc() that can be used to parse
# information about vtables.
#
# Inputs expected by ParseStructureFilesGcc():
# - A list of absolute paths of structure files to process (list of strings).
#   These files must be accessible for read.
# - A list of interesting classes (list of strings, each entry is the full name
#   (full namespace, without leading ::) of one class).
#
# ParseStructureFilesGcc() returns a dictionary that maps strings (full (with
# full namespace, without leading ::) names of classes) to VtableInfo objects.
# In case of error, None is returned and an error message is printed.
#
#
# The expected format of the entries about vtables in the parsed file is:
#
# Vtable for <class name, full namespace, no leading ::>
# <class name, full namespace, no leading ::>::<mangled name of vtable>: <number> entries
# <offset in bytes from the start of the vtable> (int (*)(...)) <unmangled function name>
#
# The last line may be present multiple times. Such a section about one vtable
# is terminated by a blank line (only whitespaces on it).
################################################################################

from os import access, R_OK, W_OK
from os.path import isfile

from parsers.utils import MergeFileInformation
from parsers.vtable_info import VtableInfo

########################################
# Parses one class structure file to extract information about vtables from it.
#
# input parameters:
# - path (string): Full path of the file to parse. Must be accessible for read.
# - class list (list of strings): list of interesting classes (one entry is one
#                                 name, full namespace, no leading ::)
#
# Returns a dictionary that maps class names (full namespace, no leading ::) to
# VtableInfo. In case of error, returns None and prints an error message.
#
########################################
def ParseStructureFile(path, class_list):
  example = "\nExample of vtable for better understanding of this error:\n\n"
  example = example + "Vtable for example::exampleclass"
  example = example + "example::exampleclass::_ZTVN1example12exampleclassE: 4 entries"
  example = example + "0     (int (*)(...))0"
  example = example + "8     (int (*)(...))(& _ZTIN1example12exampleclassE)"
  example = example + "16    (int (*)(...))example::exampleclass::examplefunction"
  example = example + "24    (int (*)(...))__cxa_pure_virtual"

  result = {}

  # searching for the start of an interesting vtable
  state_searching = 1

  # encountered start of interesting vtable, searching for entries of that table
  state_starting = 2

  # parsing entries of the vtable
  state_parsing = 3

  # Current state. See above for list of possible states.
  state = state_searching

  current_class = ""
  expected_number_of_entries = 0
  entry_counter = 0

  with open(path, 'r') as file:
    for current_line in file:
      if state == state_searching:
        if current_line.startswith("Vtable for"):
          class_name = current_line.split("Vtable for", 1)[1].strip()
          if class_name in class_list:
            if class_name in result:
              message = "Error in file \"" + path + "\". Multiple vtables for "
              message = message + "class \"" + class_name + "\" found."
              print(message)
              return None
            current_class = class_name
            state = state_starting

      elif state == state_starting:
        if not current_line.startswith(current_class + "::"):
          message = "Error in file \"" + path + "\". Entry for vtable of class "
          message = message + "\"" + current_class + "\" does not have expected"
          message = message + " format. Second line of entry does not start "
          message = message + "with \"" + current_class + "::\"."
          message = message + example
          print(message)
          return None
        elif current_line.split(current_class + "::")[1].count(":") != 1:
          message = "Error in file \"" + path + "\". Entry for vtable of class "
          message = message + "\"" + current_class + "\" does not have expected"
          message = message + " format. Count of \":\" character in part \""
          message = message + current_line.split(current_class + "::")[1] + "\""
          message = message + " of that line does not match expectation (1)."
          message = message + example
          print(message)
          return None
        else:
          after_class = current_line.split(current_class + "::")[1]
          mangled_name = after_class.split(":")[0].strip()
          count_part = after_class.split(":")[1].strip()
          if len(mangled_name) == 0:
            message = "Error in file \"" + path + "\". Entry for vtable of "
            message = message + "class \"" + current_class + "\" does not have "
            message = message + "expected format. Mangled name of vtable is "
            message = message + "empty in line \"" + current_line + "\"."
            message = message + example
            print(message)
            return None
          elif len(count_part) == 0:
            message = "Error in file \"" + path + "\". Entry for vtable of "
            message = message + "class \"" + current_class + "\" does not have "
            message = message + "expected format. No number of entries found "
            message = message + "in line \"" + current_line + "\"."
            message = message + example
            print(message)
            return None
          elif count_part.count("entries") != 1:
            message = "Error in file \"" + path + "\". Entry for vtable of "
            message = message + "class \"" + current_class + "\" does not have "
            message = message + "expected format. Keyword \"entries\" not found"
            message = message + " in part about number of entries in line \""
            message = message + current_line + "\"."
            message = message + example
            print(message)
            return None
          elif not count_part.split("entries")[0].strip().isdigit():
            message = "Error in file \"" + path + "\". Entry for vtable of "
            message = message + "class \"" + current_class + "\" does not have "
            message = message + "expected format. Number of entries in line \""
            message = message + current_line + "\" ("
            message = message + count_part.split("entries")[0].strip()
            message = message + ") is not a number."
            message = message + example
            print(message)
            return None
          else:
            expected_number_of_entries = int(count_part.split("entries")[0].strip())
            result[current_class] = VtableInfo(mangled_name)
            state = state_parsing

      else: # state == state_parsing
        if current_line.count("(int (*)(...))") != 1:
          if entry_counter != expected_number_of_entries:
            message = "Error in file \"" + path + "\". Entry for vtable of "
            message = message + "class \"" + current_class + "\" does not have "
            message = message + "expected format. Actual number of entries is "
            message = message + str(entry_counter) + " but according to line "
            message = message + " with mangled name of the vtable, there are "
            message = message + str(expected_number_of_entries) + " entries."
            message = message + example
            print(message)
            return None

          expected_number_of_entries = 0
          entry_counter = 0
          current_class = ""
          state = state_searching
        else:
          offset = current_line.split("(int (*)(...))")[0].strip()
          entry_content = current_line.split("(int (*)(...))")[1].strip()
          if len(offset) == 0:
            message = "Error in file \"" + path + "\". Entry for vtable of "
            message = message + "class \"" + current_class + "\" does not have "
            message = message + "expected format. No offset found in line \""
            message = current_line + "\"."
            message = message + example
            print(message)
            return None
          elif len(entry_content) == 0:
            message = "Error in file \"" + path + "\". Entry for vtable of "
            message = message + "class \"" + current_class + "\" does not have "
            message = message + "expected format. No content found in line \""
            message = current_line + "\"."
            message = message + example
            print(message)
            return None
          elif not offset.isdigit():
            message = "Error in file \"" + path + "\". Entry for vtable of "
            message = message + "class \"" + current_class + "\" does not have "
            message = message + "expected format. Offset in line \""
            message = current_line + "\" is not a number."
            message = message + example
            print(message)
            return None
          elif int(offset) != (entry_counter * 8):
            message = "Error in file \"" + path + "\". Entry for vtable of "
            message = message + "class \"" + current_class + "\" does not have "
            message = message + "expected format. Offset in line \""
            message = current_line + "\" is the expected number. Expected "
            message = message + str(entry_counter * 8) + " but got "
            message = message + str(offset) + "."
            message = message + example
            print(message)
            return None
          result[current_class].AddEntry(entry_content)
          entry_counter = entry_counter + 1

  return result


########################################
# Main function of this file. Refer to start of file for details.
########################################
def ParseStructureFilesGcc(file_list, class_list):
  # dict(string -> dict(string -> VtableInfo))
  all_file_information = {}

  for current_file in file_list:
    if isfile(current_file) and access(current_file, R_OK):
      result = ParseStructureFile(current_file, class_list)
      if result == None:
        # Error message already printed by ParseStructureFile().
        return None
      all_file_information[current_file] = result
    else:
      print("Failed to open file \"" + current_file + "\" for reading.")
      return None

  return MergeFileInformation(all_file_information)
