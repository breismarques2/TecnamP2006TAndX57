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
CMAKE_SOURCE_DIR = /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/EXPRPARSE-prefix/src/EXPRPARSE/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/EXPRPARSE-prefix/src/EXPRPARSE-build

# Include any dependencies generated for this target.
include exprcalc/CMakeFiles/exprcalc.dir/depend.make

# Include the progress variables for this target.
include exprcalc/CMakeFiles/exprcalc.dir/progress.make

# Include the compile flags for this target's objects.
include exprcalc/CMakeFiles/exprcalc.dir/flags.make

exprcalc/CMakeFiles/exprcalc.dir/exprcalc.cpp.o: exprcalc/CMakeFiles/exprcalc.dir/flags.make
exprcalc/CMakeFiles/exprcalc.dir/exprcalc.cpp.o: /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/EXPRPARSE-prefix/src/EXPRPARSE/src/exprcalc/exprcalc.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/EXPRPARSE-prefix/src/EXPRPARSE-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object exprcalc/CMakeFiles/exprcalc.dir/exprcalc.cpp.o"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/EXPRPARSE-prefix/src/EXPRPARSE-build/exprcalc && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/exprcalc.dir/exprcalc.cpp.o -c /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/EXPRPARSE-prefix/src/EXPRPARSE/src/exprcalc/exprcalc.cpp

exprcalc/CMakeFiles/exprcalc.dir/exprcalc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exprcalc.dir/exprcalc.cpp.i"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/EXPRPARSE-prefix/src/EXPRPARSE-build/exprcalc && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/EXPRPARSE-prefix/src/EXPRPARSE/src/exprcalc/exprcalc.cpp > CMakeFiles/exprcalc.dir/exprcalc.cpp.i

exprcalc/CMakeFiles/exprcalc.dir/exprcalc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exprcalc.dir/exprcalc.cpp.s"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/EXPRPARSE-prefix/src/EXPRPARSE-build/exprcalc && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/EXPRPARSE-prefix/src/EXPRPARSE/src/exprcalc/exprcalc.cpp -o CMakeFiles/exprcalc.dir/exprcalc.cpp.s

exprcalc/CMakeFiles/exprcalc.dir/exprcalc.cpp.o.requires:

.PHONY : exprcalc/CMakeFiles/exprcalc.dir/exprcalc.cpp.o.requires

exprcalc/CMakeFiles/exprcalc.dir/exprcalc.cpp.o.provides: exprcalc/CMakeFiles/exprcalc.dir/exprcalc.cpp.o.requires
	$(MAKE) -f exprcalc/CMakeFiles/exprcalc.dir/build.make exprcalc/CMakeFiles/exprcalc.dir/exprcalc.cpp.o.provides.build
.PHONY : exprcalc/CMakeFiles/exprcalc.dir/exprcalc.cpp.o.provides

exprcalc/CMakeFiles/exprcalc.dir/exprcalc.cpp.o.provides.build: exprcalc/CMakeFiles/exprcalc.dir/exprcalc.cpp.o


# Object files for target exprcalc
exprcalc_OBJECTS = \
"CMakeFiles/exprcalc.dir/exprcalc.cpp.o"

# External object files for target exprcalc
exprcalc_EXTERNAL_OBJECTS =

exprcalc/exprcalc: exprcalc/CMakeFiles/exprcalc.dir/exprcalc.cpp.o
exprcalc/exprcalc: exprcalc/CMakeFiles/exprcalc.dir/build.make
exprcalc/exprcalc: exprparse/libexprparse.a
exprcalc/exprcalc: exprcalc/CMakeFiles/exprcalc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/EXPRPARSE-prefix/src/EXPRPARSE-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable exprcalc"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/EXPRPARSE-prefix/src/EXPRPARSE-build/exprcalc && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/exprcalc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
exprcalc/CMakeFiles/exprcalc.dir/build: exprcalc/exprcalc

.PHONY : exprcalc/CMakeFiles/exprcalc.dir/build

exprcalc/CMakeFiles/exprcalc.dir/requires: exprcalc/CMakeFiles/exprcalc.dir/exprcalc.cpp.o.requires

.PHONY : exprcalc/CMakeFiles/exprcalc.dir/requires

exprcalc/CMakeFiles/exprcalc.dir/clean:
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/EXPRPARSE-prefix/src/EXPRPARSE-build/exprcalc && $(CMAKE_COMMAND) -P CMakeFiles/exprcalc.dir/cmake_clean.cmake
.PHONY : exprcalc/CMakeFiles/exprcalc.dir/clean

exprcalc/CMakeFiles/exprcalc.dir/depend:
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/EXPRPARSE-prefix/src/EXPRPARSE-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/EXPRPARSE-prefix/src/EXPRPARSE/src /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/EXPRPARSE-prefix/src/EXPRPARSE/src/exprcalc /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/EXPRPARSE-prefix/src/EXPRPARSE-build /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/EXPRPARSE-prefix/src/EXPRPARSE-build/exprcalc /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/EXPRPARSE-prefix/src/EXPRPARSE-build/exprcalc/CMakeFiles/exprcalc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : exprcalc/CMakeFiles/exprcalc.dir/depend

