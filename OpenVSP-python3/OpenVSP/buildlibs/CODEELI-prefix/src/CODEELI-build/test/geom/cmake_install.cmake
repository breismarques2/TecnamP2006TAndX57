# Install script for directory: /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI/test/geom

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix")
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

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI-build/test/geom/bounding_box/cmake_install.cmake")
  include("/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI-build/test/geom/fit_container/cmake_install.cmake")
  include("/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI-build/test/geom/bezier_curve/cmake_install.cmake")
  include("/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI-build/test/geom/piecewise_curve/cmake_install.cmake")
  include("/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI-build/test/geom/bezier_surface/cmake_install.cmake")
  include("/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI-build/test/geom/piecewise_surface/cmake_install.cmake")
  include("/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI-build/test/geom/minimum_distance/cmake_install.cmake")
  include("/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI-build/test/geom/pseudo_curve/cmake_install.cmake")

endif()

