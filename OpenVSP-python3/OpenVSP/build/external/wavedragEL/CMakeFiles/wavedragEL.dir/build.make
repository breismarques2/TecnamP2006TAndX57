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

# Include any dependencies generated for this target.
include external/wavedragEL/CMakeFiles/wavedragEL.dir/depend.make

# Include the progress variables for this target.
include external/wavedragEL/CMakeFiles/wavedragEL.dir/progress.make

# Include the compile flags for this target's objects.
include external/wavedragEL/CMakeFiles/wavedragEL.dir/flags.make

external/wavedragEL/CMakeFiles/wavedragEL.dir/wavedragEL.c.o: external/wavedragEL/CMakeFiles/wavedragEL.dir/flags.make
external/wavedragEL/CMakeFiles/wavedragEL.dir/wavedragEL.c.o: /Users/Bruno/OpenVSP-python3/OpenVSP/repo/src/external/wavedragEL/wavedragEL.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Bruno/OpenVSP-python3/OpenVSP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object external/wavedragEL/CMakeFiles/wavedragEL.dir/wavedragEL.c.o"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/build/external/wavedragEL && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/wavedragEL.dir/wavedragEL.c.o   -c /Users/Bruno/OpenVSP-python3/OpenVSP/repo/src/external/wavedragEL/wavedragEL.c

external/wavedragEL/CMakeFiles/wavedragEL.dir/wavedragEL.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/wavedragEL.dir/wavedragEL.c.i"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/build/external/wavedragEL && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Bruno/OpenVSP-python3/OpenVSP/repo/src/external/wavedragEL/wavedragEL.c > CMakeFiles/wavedragEL.dir/wavedragEL.c.i

external/wavedragEL/CMakeFiles/wavedragEL.dir/wavedragEL.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/wavedragEL.dir/wavedragEL.c.s"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/build/external/wavedragEL && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Bruno/OpenVSP-python3/OpenVSP/repo/src/external/wavedragEL/wavedragEL.c -o CMakeFiles/wavedragEL.dir/wavedragEL.c.s

external/wavedragEL/CMakeFiles/wavedragEL.dir/wavedragEL.c.o.requires:

.PHONY : external/wavedragEL/CMakeFiles/wavedragEL.dir/wavedragEL.c.o.requires

external/wavedragEL/CMakeFiles/wavedragEL.dir/wavedragEL.c.o.provides: external/wavedragEL/CMakeFiles/wavedragEL.dir/wavedragEL.c.o.requires
	$(MAKE) -f external/wavedragEL/CMakeFiles/wavedragEL.dir/build.make external/wavedragEL/CMakeFiles/wavedragEL.dir/wavedragEL.c.o.provides.build
.PHONY : external/wavedragEL/CMakeFiles/wavedragEL.dir/wavedragEL.c.o.provides

external/wavedragEL/CMakeFiles/wavedragEL.dir/wavedragEL.c.o.provides.build: external/wavedragEL/CMakeFiles/wavedragEL.dir/wavedragEL.c.o


# Object files for target wavedragEL
wavedragEL_OBJECTS = \
"CMakeFiles/wavedragEL.dir/wavedragEL.c.o"

# External object files for target wavedragEL
wavedragEL_EXTERNAL_OBJECTS =

external/wavedragEL/libwavedragEL.a: external/wavedragEL/CMakeFiles/wavedragEL.dir/wavedragEL.c.o
external/wavedragEL/libwavedragEL.a: external/wavedragEL/CMakeFiles/wavedragEL.dir/build.make
external/wavedragEL/libwavedragEL.a: external/wavedragEL/CMakeFiles/wavedragEL.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Bruno/OpenVSP-python3/OpenVSP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libwavedragEL.a"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/build/external/wavedragEL && $(CMAKE_COMMAND) -P CMakeFiles/wavedragEL.dir/cmake_clean_target.cmake
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/build/external/wavedragEL && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/wavedragEL.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
external/wavedragEL/CMakeFiles/wavedragEL.dir/build: external/wavedragEL/libwavedragEL.a

.PHONY : external/wavedragEL/CMakeFiles/wavedragEL.dir/build

external/wavedragEL/CMakeFiles/wavedragEL.dir/requires: external/wavedragEL/CMakeFiles/wavedragEL.dir/wavedragEL.c.o.requires

.PHONY : external/wavedragEL/CMakeFiles/wavedragEL.dir/requires

external/wavedragEL/CMakeFiles/wavedragEL.dir/clean:
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/build/external/wavedragEL && $(CMAKE_COMMAND) -P CMakeFiles/wavedragEL.dir/cmake_clean.cmake
.PHONY : external/wavedragEL/CMakeFiles/wavedragEL.dir/clean

external/wavedragEL/CMakeFiles/wavedragEL.dir/depend:
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Bruno/OpenVSP-python3/OpenVSP/repo/src /Users/Bruno/OpenVSP-python3/OpenVSP/repo/src/external/wavedragEL /Users/Bruno/OpenVSP-python3/OpenVSP/build /Users/Bruno/OpenVSP-python3/OpenVSP/build/external/wavedragEL /Users/Bruno/OpenVSP-python3/OpenVSP/build/external/wavedragEL/CMakeFiles/wavedragEL.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : external/wavedragEL/CMakeFiles/wavedragEL.dir/depend
