# Install script for directory: /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/include

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/../sc-install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/stepcode/express" TYPE FILE FILES
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/include/express/alg.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/include/express/basic.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/include/express/caseitem.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/include/express/dict.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/include/express/entity.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/include/express/error.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/include/express/expbasic.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/include/express/expr.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/include/express/express.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/include/express/hash.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/include/express/lexact.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/include/express/linklist.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/include/express/memory.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/include/express/object.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/include/express/resolve.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/include/express/schema.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/include/express/scope.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/include/express/stmt.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/include/express/symbol.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/include/express/type.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/include/express/variable.h"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/stepcode/exppp" TYPE FILE FILES "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/include/exppp/exppp.h")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/stepcode" TYPE FILE FILES
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/include/ordered_attrs.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/include/sc_export.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/include/sc_stdbool.h"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/stepcode" TYPE FILE FILES
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/include/sc_cf.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/include/sc_version_string.h"
    )
endif()

