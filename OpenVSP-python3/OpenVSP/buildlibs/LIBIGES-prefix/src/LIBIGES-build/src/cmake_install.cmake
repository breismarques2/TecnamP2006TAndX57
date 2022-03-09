# Install script for directory: /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix/src/LIBIGES/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix")
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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix/src/LIBIGES-build/src/libiges_static.a")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libiges_static.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libiges_static.a")
    execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libiges_static.a")
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/iges" TYPE FILE FILES
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix/src/LIBIGES/src/include/error_macros.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix/src/LIBIGES-build/src/libigesconf.h"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/iges/api" TYPE FILE FILES
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix/src/LIBIGES/src/include/api/all_api_entities.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix/src/LIBIGES/src/include/api/dll_entity100.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix/src/LIBIGES/src/include/api/dll_entity102.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix/src/LIBIGES/src/include/api/dll_entity104.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix/src/LIBIGES/src/include/api/dll_entity110.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix/src/LIBIGES/src/include/api/dll_entity120.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix/src/LIBIGES/src/include/api/dll_entity122.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix/src/LIBIGES/src/include/api/dll_entity124.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix/src/LIBIGES/src/include/api/dll_entity126.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix/src/LIBIGES/src/include/api/dll_entity128.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix/src/LIBIGES/src/include/api/dll_entity142.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix/src/LIBIGES/src/include/api/dll_entity144.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix/src/LIBIGES/src/include/api/dll_entity308.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix/src/LIBIGES/src/include/api/dll_entity314.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix/src/LIBIGES/src/include/api/dll_entity406.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix/src/LIBIGES/src/include/api/dll_entity408.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix/src/LIBIGES/src/include/api/dll_iges_curve.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix/src/LIBIGES/src/include/api/dll_iges_entity.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix/src/LIBIGES/src/include/api/dll_iges.h"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/iges/core" TYPE FILE FILES
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix/src/LIBIGES/src/include/core/all_entities.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix/src/LIBIGES/src/include/core/entity100.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix/src/LIBIGES/src/include/core/entity102.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix/src/LIBIGES/src/include/core/entity104.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix/src/LIBIGES/src/include/core/entity110.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix/src/LIBIGES/src/include/core/entity120.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix/src/LIBIGES/src/include/core/entity122.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix/src/LIBIGES/src/include/core/entity124.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix/src/LIBIGES/src/include/core/entity126.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix/src/LIBIGES/src/include/core/entity128.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix/src/LIBIGES/src/include/core/entity142.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix/src/LIBIGES/src/include/core/entity144.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix/src/LIBIGES/src/include/core/entity154.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix/src/LIBIGES/src/include/core/entity164.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix/src/LIBIGES/src/include/core/entity180.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix/src/LIBIGES/src/include/core/entity184.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix/src/LIBIGES/src/include/core/entity186.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix/src/LIBIGES/src/include/core/entity308.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix/src/LIBIGES/src/include/core/entity314.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix/src/LIBIGES/src/include/core/entity406.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix/src/LIBIGES/src/include/core/entity408.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix/src/LIBIGES/src/include/core/entity430.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix/src/LIBIGES/src/include/core/entity502.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix/src/LIBIGES/src/include/core/entity504.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix/src/LIBIGES/src/include/core/entity508.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix/src/LIBIGES/src/include/core/entity510.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix/src/LIBIGES/src/include/core/entity514.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix/src/LIBIGES/src/include/core/entityNULL.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix/src/LIBIGES/src/include/core/iges_curve.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix/src/LIBIGES/src/include/core/iges_entity.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix/src/LIBIGES/src/include/core/iges.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix/src/LIBIGES/src/include/core/iges_base.h"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/iges/geom" TYPE FILE FILES
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix/src/LIBIGES/src/include/geom/mcad_utils.h"
    "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/LIBIGES-prefix/src/LIBIGES/src/include/geom/mcad_elements.h"
    )
endif()

