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
include external/sixseries/CMakeFiles/sixseries.dir/depend.make

# Include the progress variables for this target.
include external/sixseries/CMakeFiles/sixseries.dir/progress.make

# Include the compile flags for this target's objects.
include external/sixseries/CMakeFiles/sixseries.dir/flags.make

external/sixseries/CMakeFiles/sixseries.dir/NACA_6_series.c.o: external/sixseries/CMakeFiles/sixseries.dir/flags.make
external/sixseries/CMakeFiles/sixseries.dir/NACA_6_series.c.o: /Users/Bruno/OpenVSP-python3/OpenVSP/repo/src/external/sixseries/NACA_6_series.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Bruno/OpenVSP-python3/OpenVSP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object external/sixseries/CMakeFiles/sixseries.dir/NACA_6_series.c.o"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/build/external/sixseries && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sixseries.dir/NACA_6_series.c.o   -c /Users/Bruno/OpenVSP-python3/OpenVSP/repo/src/external/sixseries/NACA_6_series.c

external/sixseries/CMakeFiles/sixseries.dir/NACA_6_series.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sixseries.dir/NACA_6_series.c.i"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/build/external/sixseries && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Bruno/OpenVSP-python3/OpenVSP/repo/src/external/sixseries/NACA_6_series.c > CMakeFiles/sixseries.dir/NACA_6_series.c.i

external/sixseries/CMakeFiles/sixseries.dir/NACA_6_series.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sixseries.dir/NACA_6_series.c.s"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/build/external/sixseries && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Bruno/OpenVSP-python3/OpenVSP/repo/src/external/sixseries/NACA_6_series.c -o CMakeFiles/sixseries.dir/NACA_6_series.c.s

external/sixseries/CMakeFiles/sixseries.dir/NACA_6_series.c.o.requires:

.PHONY : external/sixseries/CMakeFiles/sixseries.dir/NACA_6_series.c.o.requires

external/sixseries/CMakeFiles/sixseries.dir/NACA_6_series.c.o.provides: external/sixseries/CMakeFiles/sixseries.dir/NACA_6_series.c.o.requires
	$(MAKE) -f external/sixseries/CMakeFiles/sixseries.dir/build.make external/sixseries/CMakeFiles/sixseries.dir/NACA_6_series.c.o.provides.build
.PHONY : external/sixseries/CMakeFiles/sixseries.dir/NACA_6_series.c.o.provides

external/sixseries/CMakeFiles/sixseries.dir/NACA_6_series.c.o.provides.build: external/sixseries/CMakeFiles/sixseries.dir/NACA_6_series.c.o


external/sixseries/CMakeFiles/sixseries.dir/r_sign.c.o: external/sixseries/CMakeFiles/sixseries.dir/flags.make
external/sixseries/CMakeFiles/sixseries.dir/r_sign.c.o: /Users/Bruno/OpenVSP-python3/OpenVSP/repo/src/external/sixseries/r_sign.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Bruno/OpenVSP-python3/OpenVSP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object external/sixseries/CMakeFiles/sixseries.dir/r_sign.c.o"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/build/external/sixseries && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sixseries.dir/r_sign.c.o   -c /Users/Bruno/OpenVSP-python3/OpenVSP/repo/src/external/sixseries/r_sign.c

external/sixseries/CMakeFiles/sixseries.dir/r_sign.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sixseries.dir/r_sign.c.i"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/build/external/sixseries && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Bruno/OpenVSP-python3/OpenVSP/repo/src/external/sixseries/r_sign.c > CMakeFiles/sixseries.dir/r_sign.c.i

external/sixseries/CMakeFiles/sixseries.dir/r_sign.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sixseries.dir/r_sign.c.s"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/build/external/sixseries && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Bruno/OpenVSP-python3/OpenVSP/repo/src/external/sixseries/r_sign.c -o CMakeFiles/sixseries.dir/r_sign.c.s

external/sixseries/CMakeFiles/sixseries.dir/r_sign.c.o.requires:

.PHONY : external/sixseries/CMakeFiles/sixseries.dir/r_sign.c.o.requires

external/sixseries/CMakeFiles/sixseries.dir/r_sign.c.o.provides: external/sixseries/CMakeFiles/sixseries.dir/r_sign.c.o.requires
	$(MAKE) -f external/sixseries/CMakeFiles/sixseries.dir/build.make external/sixseries/CMakeFiles/sixseries.dir/r_sign.c.o.provides.build
.PHONY : external/sixseries/CMakeFiles/sixseries.dir/r_sign.c.o.provides

external/sixseries/CMakeFiles/sixseries.dir/r_sign.c.o.provides.build: external/sixseries/CMakeFiles/sixseries.dir/r_sign.c.o


external/sixseries/CMakeFiles/sixseries.dir/s_cmp.c.o: external/sixseries/CMakeFiles/sixseries.dir/flags.make
external/sixseries/CMakeFiles/sixseries.dir/s_cmp.c.o: /Users/Bruno/OpenVSP-python3/OpenVSP/repo/src/external/sixseries/s_cmp.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Bruno/OpenVSP-python3/OpenVSP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object external/sixseries/CMakeFiles/sixseries.dir/s_cmp.c.o"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/build/external/sixseries && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sixseries.dir/s_cmp.c.o   -c /Users/Bruno/OpenVSP-python3/OpenVSP/repo/src/external/sixseries/s_cmp.c

external/sixseries/CMakeFiles/sixseries.dir/s_cmp.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sixseries.dir/s_cmp.c.i"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/build/external/sixseries && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Bruno/OpenVSP-python3/OpenVSP/repo/src/external/sixseries/s_cmp.c > CMakeFiles/sixseries.dir/s_cmp.c.i

external/sixseries/CMakeFiles/sixseries.dir/s_cmp.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sixseries.dir/s_cmp.c.s"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/build/external/sixseries && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Bruno/OpenVSP-python3/OpenVSP/repo/src/external/sixseries/s_cmp.c -o CMakeFiles/sixseries.dir/s_cmp.c.s

external/sixseries/CMakeFiles/sixseries.dir/s_cmp.c.o.requires:

.PHONY : external/sixseries/CMakeFiles/sixseries.dir/s_cmp.c.o.requires

external/sixseries/CMakeFiles/sixseries.dir/s_cmp.c.o.provides: external/sixseries/CMakeFiles/sixseries.dir/s_cmp.c.o.requires
	$(MAKE) -f external/sixseries/CMakeFiles/sixseries.dir/build.make external/sixseries/CMakeFiles/sixseries.dir/s_cmp.c.o.provides.build
.PHONY : external/sixseries/CMakeFiles/sixseries.dir/s_cmp.c.o.provides

external/sixseries/CMakeFiles/sixseries.dir/s_cmp.c.o.provides.build: external/sixseries/CMakeFiles/sixseries.dir/s_cmp.c.o


external/sixseries/CMakeFiles/sixseries.dir/s_copy.c.o: external/sixseries/CMakeFiles/sixseries.dir/flags.make
external/sixseries/CMakeFiles/sixseries.dir/s_copy.c.o: /Users/Bruno/OpenVSP-python3/OpenVSP/repo/src/external/sixseries/s_copy.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Bruno/OpenVSP-python3/OpenVSP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object external/sixseries/CMakeFiles/sixseries.dir/s_copy.c.o"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/build/external/sixseries && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sixseries.dir/s_copy.c.o   -c /Users/Bruno/OpenVSP-python3/OpenVSP/repo/src/external/sixseries/s_copy.c

external/sixseries/CMakeFiles/sixseries.dir/s_copy.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sixseries.dir/s_copy.c.i"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/build/external/sixseries && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Bruno/OpenVSP-python3/OpenVSP/repo/src/external/sixseries/s_copy.c > CMakeFiles/sixseries.dir/s_copy.c.i

external/sixseries/CMakeFiles/sixseries.dir/s_copy.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sixseries.dir/s_copy.c.s"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/build/external/sixseries && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Bruno/OpenVSP-python3/OpenVSP/repo/src/external/sixseries/s_copy.c -o CMakeFiles/sixseries.dir/s_copy.c.s

external/sixseries/CMakeFiles/sixseries.dir/s_copy.c.o.requires:

.PHONY : external/sixseries/CMakeFiles/sixseries.dir/s_copy.c.o.requires

external/sixseries/CMakeFiles/sixseries.dir/s_copy.c.o.provides: external/sixseries/CMakeFiles/sixseries.dir/s_copy.c.o.requires
	$(MAKE) -f external/sixseries/CMakeFiles/sixseries.dir/build.make external/sixseries/CMakeFiles/sixseries.dir/s_copy.c.o.provides.build
.PHONY : external/sixseries/CMakeFiles/sixseries.dir/s_copy.c.o.provides

external/sixseries/CMakeFiles/sixseries.dir/s_copy.c.o.provides.build: external/sixseries/CMakeFiles/sixseries.dir/s_copy.c.o


external/sixseries/CMakeFiles/sixseries.dir/s_stop.c.o: external/sixseries/CMakeFiles/sixseries.dir/flags.make
external/sixseries/CMakeFiles/sixseries.dir/s_stop.c.o: /Users/Bruno/OpenVSP-python3/OpenVSP/repo/src/external/sixseries/s_stop.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Bruno/OpenVSP-python3/OpenVSP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object external/sixseries/CMakeFiles/sixseries.dir/s_stop.c.o"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/build/external/sixseries && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sixseries.dir/s_stop.c.o   -c /Users/Bruno/OpenVSP-python3/OpenVSP/repo/src/external/sixseries/s_stop.c

external/sixseries/CMakeFiles/sixseries.dir/s_stop.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sixseries.dir/s_stop.c.i"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/build/external/sixseries && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Bruno/OpenVSP-python3/OpenVSP/repo/src/external/sixseries/s_stop.c > CMakeFiles/sixseries.dir/s_stop.c.i

external/sixseries/CMakeFiles/sixseries.dir/s_stop.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sixseries.dir/s_stop.c.s"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/build/external/sixseries && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Bruno/OpenVSP-python3/OpenVSP/repo/src/external/sixseries/s_stop.c -o CMakeFiles/sixseries.dir/s_stop.c.s

external/sixseries/CMakeFiles/sixseries.dir/s_stop.c.o.requires:

.PHONY : external/sixseries/CMakeFiles/sixseries.dir/s_stop.c.o.requires

external/sixseries/CMakeFiles/sixseries.dir/s_stop.c.o.provides: external/sixseries/CMakeFiles/sixseries.dir/s_stop.c.o.requires
	$(MAKE) -f external/sixseries/CMakeFiles/sixseries.dir/build.make external/sixseries/CMakeFiles/sixseries.dir/s_stop.c.o.provides.build
.PHONY : external/sixseries/CMakeFiles/sixseries.dir/s_stop.c.o.provides

external/sixseries/CMakeFiles/sixseries.dir/s_stop.c.o.provides.build: external/sixseries/CMakeFiles/sixseries.dir/s_stop.c.o


# Object files for target sixseries
sixseries_OBJECTS = \
"CMakeFiles/sixseries.dir/NACA_6_series.c.o" \
"CMakeFiles/sixseries.dir/r_sign.c.o" \
"CMakeFiles/sixseries.dir/s_cmp.c.o" \
"CMakeFiles/sixseries.dir/s_copy.c.o" \
"CMakeFiles/sixseries.dir/s_stop.c.o"

# External object files for target sixseries
sixseries_EXTERNAL_OBJECTS =

external/sixseries/libsixseries.a: external/sixseries/CMakeFiles/sixseries.dir/NACA_6_series.c.o
external/sixseries/libsixseries.a: external/sixseries/CMakeFiles/sixseries.dir/r_sign.c.o
external/sixseries/libsixseries.a: external/sixseries/CMakeFiles/sixseries.dir/s_cmp.c.o
external/sixseries/libsixseries.a: external/sixseries/CMakeFiles/sixseries.dir/s_copy.c.o
external/sixseries/libsixseries.a: external/sixseries/CMakeFiles/sixseries.dir/s_stop.c.o
external/sixseries/libsixseries.a: external/sixseries/CMakeFiles/sixseries.dir/build.make
external/sixseries/libsixseries.a: external/sixseries/CMakeFiles/sixseries.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Bruno/OpenVSP-python3/OpenVSP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C static library libsixseries.a"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/build/external/sixseries && $(CMAKE_COMMAND) -P CMakeFiles/sixseries.dir/cmake_clean_target.cmake
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/build/external/sixseries && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sixseries.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
external/sixseries/CMakeFiles/sixseries.dir/build: external/sixseries/libsixseries.a

.PHONY : external/sixseries/CMakeFiles/sixseries.dir/build

external/sixseries/CMakeFiles/sixseries.dir/requires: external/sixseries/CMakeFiles/sixseries.dir/NACA_6_series.c.o.requires
external/sixseries/CMakeFiles/sixseries.dir/requires: external/sixseries/CMakeFiles/sixseries.dir/r_sign.c.o.requires
external/sixseries/CMakeFiles/sixseries.dir/requires: external/sixseries/CMakeFiles/sixseries.dir/s_cmp.c.o.requires
external/sixseries/CMakeFiles/sixseries.dir/requires: external/sixseries/CMakeFiles/sixseries.dir/s_copy.c.o.requires
external/sixseries/CMakeFiles/sixseries.dir/requires: external/sixseries/CMakeFiles/sixseries.dir/s_stop.c.o.requires

.PHONY : external/sixseries/CMakeFiles/sixseries.dir/requires

external/sixseries/CMakeFiles/sixseries.dir/clean:
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/build/external/sixseries && $(CMAKE_COMMAND) -P CMakeFiles/sixseries.dir/cmake_clean.cmake
.PHONY : external/sixseries/CMakeFiles/sixseries.dir/clean

external/sixseries/CMakeFiles/sixseries.dir/depend:
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Bruno/OpenVSP-python3/OpenVSP/repo/src /Users/Bruno/OpenVSP-python3/OpenVSP/repo/src/external/sixseries /Users/Bruno/OpenVSP-python3/OpenVSP/build /Users/Bruno/OpenVSP-python3/OpenVSP/build/external/sixseries /Users/Bruno/OpenVSP-python3/OpenVSP/build/external/sixseries/CMakeFiles/sixseries.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : external/sixseries/CMakeFiles/sixseries.dir/depend
