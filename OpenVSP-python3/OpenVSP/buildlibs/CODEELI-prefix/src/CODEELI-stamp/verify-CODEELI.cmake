# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

if("/Users/Bruno/OpenVSP-python3/OpenVSP/repo/Libraries/Code-Eli-b6e1bd3e17ce.zip" STREQUAL "")
  message(FATAL_ERROR "LOCAL can't be empty")
endif()

if(NOT EXISTS "/Users/Bruno/OpenVSP-python3/OpenVSP/repo/Libraries/Code-Eli-b6e1bd3e17ce.zip")
  message(FATAL_ERROR "File not found: /Users/Bruno/OpenVSP-python3/OpenVSP/repo/Libraries/Code-Eli-b6e1bd3e17ce.zip")
endif()

if("" STREQUAL "")
  message(WARNING "File will not be verified since no URL_HASH specified")
  return()
endif()

if("" STREQUAL "")
  message(FATAL_ERROR "EXPECT_VALUE can't be empty")
endif()

message(STATUS "verifying file...
     file='/Users/Bruno/OpenVSP-python3/OpenVSP/repo/Libraries/Code-Eli-b6e1bd3e17ce.zip'")

file("" "/Users/Bruno/OpenVSP-python3/OpenVSP/repo/Libraries/Code-Eli-b6e1bd3e17ce.zip" actual_value)

if(NOT "${actual_value}" STREQUAL "")
  message(FATAL_ERROR "error:  hash of
  /Users/Bruno/OpenVSP-python3/OpenVSP/repo/Libraries/Code-Eli-b6e1bd3e17ce.zip
does not match expected value
  expected: ''
    actual: '${actual_value}'
")
endif()

message(STATUS "verifying file... done")
