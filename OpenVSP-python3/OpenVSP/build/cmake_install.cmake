# Install script for directory: /Users/Bruno/OpenVSP-python3/OpenVSP/repo/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/airfoil" TYPE DIRECTORY FILES "/Users/Bruno/OpenVSP-python3/OpenVSP/repo/src/../examples/airfoil/")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/CustomScripts" TYPE DIRECTORY FILES "/Users/Bruno/OpenVSP-python3/OpenVSP/repo/src/../examples/CustomScripts/")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/matlab" TYPE DIRECTORY FILES "/Users/Bruno/OpenVSP-python3/OpenVSP/repo/src/../examples/matlab/")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/scripts" TYPE DIRECTORY FILES "/Users/Bruno/OpenVSP-python3/OpenVSP/repo/src/../examples/scripts/")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/textures" TYPE DIRECTORY FILES "/Users/Bruno/OpenVSP-python3/OpenVSP/repo/src/../examples/textures/")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/vspaero_ex" TYPE DIRECTORY FILES "/Users/Bruno/OpenVSP-python3/OpenVSP/repo/src/../examples/vspaero_ex/")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE FILE FILES "/Users/Bruno/OpenVSP-python3/OpenVSP/repo/src/../LICENSE")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE FILE FILES "/Users/Bruno/OpenVSP-python3/OpenVSP/repo/src/../README.md")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE FILE FILES "/Users/Bruno/OpenVSP-python3/OpenVSP/repo/src/../vspIcon.png")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/Bruno/OpenVSP-python3/OpenVSP/build/external/cmake_install.cmake")
  include("/Users/Bruno/OpenVSP-python3/OpenVSP/build/external/angelscript/sdk/cmake_install.cmake")
  include("/Users/Bruno/OpenVSP-python3/OpenVSP/build/vsp_graphic/cmake_install.cmake")
  include("/Users/Bruno/OpenVSP-python3/OpenVSP/build/util/cmake_install.cmake")
  include("/Users/Bruno/OpenVSP-python3/OpenVSP/build/xmlvsp/cmake_install.cmake")
  include("/Users/Bruno/OpenVSP-python3/OpenVSP/build/geom_core/cmake_install.cmake")
  include("/Users/Bruno/OpenVSP-python3/OpenVSP/build/cfd_mesh/cmake_install.cmake")
  include("/Users/Bruno/OpenVSP-python3/OpenVSP/build/gui_and_draw/cmake_install.cmake")
  include("/Users/Bruno/OpenVSP-python3/OpenVSP/build/geom_api/cmake_install.cmake")
  include("/Users/Bruno/OpenVSP-python3/OpenVSP/build/vsp/cmake_install.cmake")
  include("/Users/Bruno/OpenVSP-python3/OpenVSP/build/python_api/cmake_install.cmake")
  include("/Users/Bruno/OpenVSP-python3/OpenVSP/build/vsp_aero/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/Users/Bruno/OpenVSP-python3/OpenVSP/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
