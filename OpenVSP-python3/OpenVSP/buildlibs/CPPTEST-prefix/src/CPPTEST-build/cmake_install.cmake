# Install script for directory: /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CPPTEST-prefix/src/CPPTEST

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CPPTEST-prefix")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CPPTEST-prefix/src/CPPTEST-build/libcpptest.a")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcpptest.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcpptest.a")
    execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcpptest.a")
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CPPTEST-prefix/src/CPPTEST/src/cpptest-assert.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CPPTEST-prefix/src/CPPTEST/src/cpptest-collectoroutput.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CPPTEST-prefix/src/CPPTEST/src/cpptest-compileroutput.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CPPTEST-prefix/src/CPPTEST/src/cpptest-htmloutput.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CPPTEST-prefix/src/CPPTEST/src/cpptest-output.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CPPTEST-prefix/src/CPPTEST/src/cpptest-source.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CPPTEST-prefix/src/CPPTEST/src/cpptest-suite.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CPPTEST-prefix/src/CPPTEST/src/cpptest-textoutput.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CPPTEST-prefix/src/CPPTEST/src/cpptest-time.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CPPTEST-prefix/src/CPPTEST/src/cpptest.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CPPTEST-prefix/src/CPPTEST-build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
