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
include example/vsp_pod/CMakeFiles/VSPPodExample.dir/depend.make

# Include the progress variables for this target.
include example/vsp_pod/CMakeFiles/VSPPodExample.dir/progress.make

# Include the compile flags for this target's objects.
include example/vsp_pod/CMakeFiles/VSPPodExample.dir/flags.make

example/vsp_pod/CMakeFiles/VSPPodExample.dir/vsp_pod.cpp.o: example/vsp_pod/CMakeFiles/VSPPodExample.dir/flags.make
example/vsp_pod/CMakeFiles/VSPPodExample.dir/vsp_pod.cpp.o: /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI/example/vsp_pod/vsp_pod.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object example/vsp_pod/CMakeFiles/VSPPodExample.dir/vsp_pod.cpp.o"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI-build/example/vsp_pod && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VSPPodExample.dir/vsp_pod.cpp.o -c /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI/example/vsp_pod/vsp_pod.cpp

example/vsp_pod/CMakeFiles/VSPPodExample.dir/vsp_pod.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VSPPodExample.dir/vsp_pod.cpp.i"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI-build/example/vsp_pod && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI/example/vsp_pod/vsp_pod.cpp > CMakeFiles/VSPPodExample.dir/vsp_pod.cpp.i

example/vsp_pod/CMakeFiles/VSPPodExample.dir/vsp_pod.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VSPPodExample.dir/vsp_pod.cpp.s"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI-build/example/vsp_pod && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI/example/vsp_pod/vsp_pod.cpp -o CMakeFiles/VSPPodExample.dir/vsp_pod.cpp.s

example/vsp_pod/CMakeFiles/VSPPodExample.dir/vsp_pod.cpp.o.requires:

.PHONY : example/vsp_pod/CMakeFiles/VSPPodExample.dir/vsp_pod.cpp.o.requires

example/vsp_pod/CMakeFiles/VSPPodExample.dir/vsp_pod.cpp.o.provides: example/vsp_pod/CMakeFiles/VSPPodExample.dir/vsp_pod.cpp.o.requires
	$(MAKE) -f example/vsp_pod/CMakeFiles/VSPPodExample.dir/build.make example/vsp_pod/CMakeFiles/VSPPodExample.dir/vsp_pod.cpp.o.provides.build
.PHONY : example/vsp_pod/CMakeFiles/VSPPodExample.dir/vsp_pod.cpp.o.provides

example/vsp_pod/CMakeFiles/VSPPodExample.dir/vsp_pod.cpp.o.provides.build: example/vsp_pod/CMakeFiles/VSPPodExample.dir/vsp_pod.cpp.o


# Object files for target VSPPodExample
VSPPodExample_OBJECTS = \
"CMakeFiles/VSPPodExample.dir/vsp_pod.cpp.o"

# External object files for target VSPPodExample
VSPPodExample_EXTERNAL_OBJECTS =

example/vsp_pod/VSPPodExample: example/vsp_pod/CMakeFiles/VSPPodExample.dir/vsp_pod.cpp.o
example/vsp_pod/VSPPodExample: example/vsp_pod/CMakeFiles/VSPPodExample.dir/build.make
example/vsp_pod/VSPPodExample: example/vsp_pod/CMakeFiles/VSPPodExample.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable VSPPodExample"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI-build/example/vsp_pod && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/VSPPodExample.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
example/vsp_pod/CMakeFiles/VSPPodExample.dir/build: example/vsp_pod/VSPPodExample

.PHONY : example/vsp_pod/CMakeFiles/VSPPodExample.dir/build

example/vsp_pod/CMakeFiles/VSPPodExample.dir/requires: example/vsp_pod/CMakeFiles/VSPPodExample.dir/vsp_pod.cpp.o.requires

.PHONY : example/vsp_pod/CMakeFiles/VSPPodExample.dir/requires

example/vsp_pod/CMakeFiles/VSPPodExample.dir/clean:
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI-build/example/vsp_pod && $(CMAKE_COMMAND) -P CMakeFiles/VSPPodExample.dir/cmake_clean.cmake
.PHONY : example/vsp_pod/CMakeFiles/VSPPodExample.dir/clean

example/vsp_pod/CMakeFiles/VSPPodExample.dir/depend:
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI/example/vsp_pod /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI-build /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI-build/example/vsp_pod /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI-build/example/vsp_pod/CMakeFiles/VSPPodExample.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : example/vsp_pod/CMakeFiles/VSPPodExample.dir/depend

