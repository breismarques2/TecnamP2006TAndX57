# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI-build

# Include any dependencies generated for this target.
include test/geom/pseudo_curve/CMakeFiles/CSTAirfoilTest.dir/depend.make

# Include the progress variables for this target.
include test/geom/pseudo_curve/CMakeFiles/CSTAirfoilTest.dir/progress.make

# Include the compile flags for this target's objects.
include test/geom/pseudo_curve/CMakeFiles/CSTAirfoilTest.dir/flags.make

test/geom/pseudo_curve/CMakeFiles/CSTAirfoilTest.dir/cst_airfoil_test.cpp.o: test/geom/pseudo_curve/CMakeFiles/CSTAirfoilTest.dir/flags.make
test/geom/pseudo_curve/CMakeFiles/CSTAirfoilTest.dir/cst_airfoil_test.cpp.o: /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI/test/geom/pseudo_curve/cst_airfoil_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/geom/pseudo_curve/CMakeFiles/CSTAirfoilTest.dir/cst_airfoil_test.cpp.o"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI-build/test/geom/pseudo_curve && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CSTAirfoilTest.dir/cst_airfoil_test.cpp.o -c /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI/test/geom/pseudo_curve/cst_airfoil_test.cpp

test/geom/pseudo_curve/CMakeFiles/CSTAirfoilTest.dir/cst_airfoil_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CSTAirfoilTest.dir/cst_airfoil_test.cpp.i"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI-build/test/geom/pseudo_curve && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI/test/geom/pseudo_curve/cst_airfoil_test.cpp > CMakeFiles/CSTAirfoilTest.dir/cst_airfoil_test.cpp.i

test/geom/pseudo_curve/CMakeFiles/CSTAirfoilTest.dir/cst_airfoil_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CSTAirfoilTest.dir/cst_airfoil_test.cpp.s"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI-build/test/geom/pseudo_curve && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI/test/geom/pseudo_curve/cst_airfoil_test.cpp -o CMakeFiles/CSTAirfoilTest.dir/cst_airfoil_test.cpp.s

test/geom/pseudo_curve/CMakeFiles/CSTAirfoilTest.dir/cst_airfoil_test.cpp.o.requires:

.PHONY : test/geom/pseudo_curve/CMakeFiles/CSTAirfoilTest.dir/cst_airfoil_test.cpp.o.requires

test/geom/pseudo_curve/CMakeFiles/CSTAirfoilTest.dir/cst_airfoil_test.cpp.o.provides: test/geom/pseudo_curve/CMakeFiles/CSTAirfoilTest.dir/cst_airfoil_test.cpp.o.requires
	$(MAKE) -f test/geom/pseudo_curve/CMakeFiles/CSTAirfoilTest.dir/build.make test/geom/pseudo_curve/CMakeFiles/CSTAirfoilTest.dir/cst_airfoil_test.cpp.o.provides.build
.PHONY : test/geom/pseudo_curve/CMakeFiles/CSTAirfoilTest.dir/cst_airfoil_test.cpp.o.provides

test/geom/pseudo_curve/CMakeFiles/CSTAirfoilTest.dir/cst_airfoil_test.cpp.o.provides.build: test/geom/pseudo_curve/CMakeFiles/CSTAirfoilTest.dir/cst_airfoil_test.cpp.o


# Object files for target CSTAirfoilTest
CSTAirfoilTest_OBJECTS = \
"CMakeFiles/CSTAirfoilTest.dir/cst_airfoil_test.cpp.o"

# External object files for target CSTAirfoilTest
CSTAirfoilTest_EXTERNAL_OBJECTS =

test/geom/pseudo_curve/CSTAirfoilTest: test/geom/pseudo_curve/CMakeFiles/CSTAirfoilTest.dir/cst_airfoil_test.cpp.o
test/geom/pseudo_curve/CSTAirfoilTest: test/geom/pseudo_curve/CMakeFiles/CSTAirfoilTest.dir/build.make
test/geom/pseudo_curve/CSTAirfoilTest: /usr/local/lib/libcpptest.dylib
test/geom/pseudo_curve/CSTAirfoilTest: test/geom/pseudo_curve/CMakeFiles/CSTAirfoilTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CSTAirfoilTest"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI-build/test/geom/pseudo_curve && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CSTAirfoilTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/geom/pseudo_curve/CMakeFiles/CSTAirfoilTest.dir/build: test/geom/pseudo_curve/CSTAirfoilTest

.PHONY : test/geom/pseudo_curve/CMakeFiles/CSTAirfoilTest.dir/build

test/geom/pseudo_curve/CMakeFiles/CSTAirfoilTest.dir/requires: test/geom/pseudo_curve/CMakeFiles/CSTAirfoilTest.dir/cst_airfoil_test.cpp.o.requires

.PHONY : test/geom/pseudo_curve/CMakeFiles/CSTAirfoilTest.dir/requires

test/geom/pseudo_curve/CMakeFiles/CSTAirfoilTest.dir/clean:
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI-build/test/geom/pseudo_curve && $(CMAKE_COMMAND) -P CMakeFiles/CSTAirfoilTest.dir/cmake_clean.cmake
.PHONY : test/geom/pseudo_curve/CMakeFiles/CSTAirfoilTest.dir/clean

test/geom/pseudo_curve/CMakeFiles/CSTAirfoilTest.dir/depend:
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI/test/geom/pseudo_curve /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI-build /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI-build/test/geom/pseudo_curve /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI-build/test/geom/pseudo_curve/CMakeFiles/CSTAirfoilTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/geom/pseudo_curve/CMakeFiles/CSTAirfoilTest.dir/depend

