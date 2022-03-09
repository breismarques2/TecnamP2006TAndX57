# Install script for directory: /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/src/exp2cxx

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/bin/exp2cxx")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/exp2cxx" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/exp2cxx")
    execute_process(COMMAND "/opt/local/bin/install_name_tool"
      -change "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/lib/libbase.2.dylib" "/usr/local/lib/libbase.2.dylib"
      -change "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/lib/libexppp.2.dylib" "/usr/local/lib/libexppp.2.dylib"
      -change "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/lib/libexpress.2.dylib" "/usr/local/lib/libexpress.2.dylib"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/exp2cxx")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/exp2cxx")
    endif()
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/bin/exp2cxx-static")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/exp2cxx-static" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/exp2cxx-static")
    execute_process(COMMAND "/opt/local/bin/install_name_tool"
      -change "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/lib/libbase.2.dylib" "/usr/local/lib/libbase.2.dylib"
      -change "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/lib/libexppp.2.dylib" "/usr/local/lib/libexppp.2.dylib"
      -change "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/lib/libexpress.2.dylib" "/usr/local/lib/libexpress.2.dylib"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/exp2cxx-static")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/exp2cxx-static")
    endif()
  endif()
endif()
