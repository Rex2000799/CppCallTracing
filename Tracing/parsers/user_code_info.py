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
# Support class for storing information about user code to be added to the
# generated callout file.
#
################################################################################

########################################
# Represents information about user code.
#
# member variables:
# - include_content (list of strings): User code for the include section, one
#                                      string per line. None if not user code is
#                                      available for includes.
# - callout_content (dict string -> list of strings): Maps unmangled name of
#                                                     the callout to the user
#                                                     code for that callout,
#                                                     maps to None if no user
#                                                     code for that callout is
#                                                     available. 
########################################
class UserCodeInfo:
  ######################################
  # Creates an instance.
  ######################################
  def __init__(self):
    self.include_content = None
    self.callout_content = {}

  ######################################
  # Adds user code for include. Overwrites previously added user code for
  # include.
  #
  # parameters:
  # - content (list of strings): The user code for include, one string per line.
  ######################################
  def AddIncludeUserCode(self, content):
    if len(content) == 0:
      self.include_content = None
    else:
      self.include_content = content

  ######################################
  # Adds user code for a callout. Overwrites previously added user code for that
  # callout.
  #
  # parameters:
  # - name (string): Unmangled name of the callout.
  # - content (list of strings): The user code for the callout, one string per
  #                              line.
  ######################################
  def AddCalloutUserCode(self, name, content):
    if len(content) == 0:
      self.callout_content[name] = None
    else:
      self.callout_content[name] = content

  ######################################
  # Gets user code for a callout.
  #
  # parameters:
  # - name (string): Unmangled name of the callout.
  #
  # Returns the content of the callout (list of strings, one string per line) or
  # None if no callout is found for input name or the callout does not require
  # user code.
  ######################################
  def GetCalloutUserCode(self, name):
    res = None
    if name in self.callout_content:
      res = self.callout_content[name]
    return res
