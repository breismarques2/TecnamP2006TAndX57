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
include test/mutil/dm/CMakeFiles/DMTest.dir/depend.make

# Include the progress variables for this target.
include test/mutil/dm/CMakeFiles/DMTest.dir/progress.make

# Include the compile flags for this target's objects.
include test/mutil/dm/CMakeFiles/DMTest.dir/flags.make

test/mutil/dm/CMakeFiles/DMTest.dir/dm_test.cpp.o: test/mutil/dm/CMakeFiles/DMTest.dir/flags.make
test/mutil/dm/CMakeFiles/DMTest.dir/dm_test.cpp.o: /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI/test/mutil/dm/dm_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/mutil/dm/CMakeFiles/DMTest.dir/dm_test.cpp.o"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI-build/test/mutil/dm && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DMTest.dir/dm_test.cpp.o -c /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI/test/mutil/dm/dm_test.cpp

test/mutil/dm/CMakeFiles/DMTest.dir/dm_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DMTest.dir/dm_test.cpp.i"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI-build/test/mutil/dm && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI/test/mutil/dm/dm_test.cpp > CMakeFiles/DMTest.dir/dm_test.cpp.i

test/mutil/dm/CMakeFiles/DMTest.dir/dm_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DMTest.dir/dm_test.cpp.s"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI-build/test/mutil/dm && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI/test/mutil/dm/dm_test.cpp -o CMakeFiles/DMTest.dir/dm_test.cpp.s

test/mutil/dm/CMakeFiles/DMTest.dir/dm_test.cpp.o.requires:

.PHONY : test/mutil/dm/CMakeFiles/DMTest.dir/dm_test.cpp.o.requires

test/mutil/dm/CMakeFiles/DMTest.dir/dm_test.cpp.o.provides: test/mutil/dm/CMakeFiles/DMTest.dir/dm_test.cpp.o.requires
	$(MAKE) -f test/mutil/dm/CMakeFiles/DMTest.dir/build.make test/mutil/dm/CMakeFiles/DMTest.dir/dm_test.cpp.o.provides.build
.PHONY : test/mutil/dm/CMakeFiles/DMTest.dir/dm_test.cpp.o.provides

test/mutil/dm/CMakeFiles/DMTest.dir/dm_test.cpp.o.provides.build: test/mutil/dm/CMakeFiles/DMTest.dir/dm_test.cpp.o


# Object files for target DMTest
DMTest_OBJECTS = \
"CMakeFiles/DMTest.dir/dm_test.cpp.o"

# External object files for target DMTest
DMTest_EXTERNAL_OBJECTS =

test/mutil/dm/DMTest: test/mutil/dm/CMakeFiles/DMTest.dir/dm_test.cpp.o
test/mutil/dm/DMTest: test/mutil/dm/CMakeFiles/DMTest.dir/build.make
test/mutil/dm/DMTest: /usr/local/lib/libcpptest.dylib
test/mutil/dm/DMTest: test/mutil/dm/CMakeFiles/DMTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable DMTest"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI-build/test/mutil/dm && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DMTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/mutil/dm/CMakeFiles/DMTest.dir/build: test/mutil/dm/DMTest

.PHONY : test/mutil/dm/CMakeFiles/DMTest.dir/build

test/mutil/dm/CMakeFiles/DMTest.dir/requires: test/mutil/dm/CMakeFiles/DMTest.dir/dm_test.cpp.o.requires

.PHONY : test/mutil/dm/CMakeFiles/DMTest.dir/requires

test/mutil/dm/CMakeFiles/DMTest.dir/clean:
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI-build/test/mutil/dm && $(CMAKE_COMMAND) -P CMakeFiles/DMTest.dir/cmake_clean.cmake
.PHONY : test/mutil/dm/CMakeFiles/DMTest.dir/clean

test/mutil/dm/CMakeFiles/DMTest.dir/depend:
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI/test/mutil/dm /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI-build /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI-build/test/mutil/dm /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI-build/test/mutil/dm/CMakeFiles/DMTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/mutil/dm/CMakeFiles/DMTest.dir/depend

