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
# Contains function ParseStructureFilesClang() that can be used to parse
# information about vtables.
#
# Inputs expected by ParseStructureFilesClang():
# - A list of absolute paths of structure files to process (list of strings).
#   These files must be accessible for read.
# - A list of interesting classes (list of strings, each entry is the full name
#   (full namespace, without leading ::) of one class).
#
# ParseStructureFilesClang() returns a dictionary that maps strings (full (with
# full namespace, without leading ::) names of classes) to VtableInfo objects.
# In case of error, None is returned and an error message is printed.
#
#
# The expected format of the entries about vtables in the parsed file is:
#
# TODO: describe format of vtable information
#
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
  # TODO: implement this
  return None


########################################
# Main function of this file. Refer to start of file for details.
########################################
def ParseStructureFilesClang(file_list, class_list):
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
