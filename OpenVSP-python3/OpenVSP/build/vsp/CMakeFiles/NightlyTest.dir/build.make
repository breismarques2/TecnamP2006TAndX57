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
CMAKE_SOURCE_DIR = /Users/Bruno/OpenVSP-python3/OpenVSP/repo/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Bruno/OpenVSP-python3/OpenVSP/build

# Utility rule file for NightlyTest.

# Include the progress variables for this target.
include vsp/CMakeFiles/NightlyTest.dir/progress.make

vsp/CMakeFiles/NightlyTest:
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/build/vsp && /Applications/CMake.app/Contents/bin/ctest -D NightlyTest

NightlyTest: vsp/CMakeFiles/NightlyTest
NightlyTest: vsp/CMakeFiles/NightlyTest.dir/build.make

.PHONY : NightlyTest

# Rule to build all files generated by this target.
vsp/CMakeFiles/NightlyTest.dir/build: NightlyTest

.PHONY : vsp/CMakeFiles/NightlyTest.dir/build

vsp/CMakeFiles/NightlyTest.dir/clean:
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/build/vsp && $(CMAKE_COMMAND) -P CMakeFiles/NightlyTest.dir/cmake_clean.cmake
.PHONY : vsp/CMakeFiles/NightlyTest.dir/clean

vsp/CMakeFiles/NightlyTest.dir/depend:
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Bruno/OpenVSP-python3/OpenVSP/repo/src /Users/Bruno/OpenVSP-python3/OpenVSP/repo/src/vsp /Users/Bruno/OpenVSP-python3/OpenVSP/build /Users/Bruno/OpenVSP-python3/OpenVSP/build/vsp /Users/Bruno/OpenVSP-python3/OpenVSP/build/vsp/CMakeFiles/NightlyTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : vsp/CMakeFiles/NightlyTest.dir/depend
