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
include geom_api/CMakeFiles/gui_interface_g.dir/depend.make

# Include the progress variables for this target.
include geom_api/CMakeFiles/gui_interface_g.dir/progress.make

# Include the compile flags for this target's objects.
include geom_api/CMakeFiles/gui_interface_g.dir/flags.make

geom_api/CMakeFiles/gui_interface_g.dir/GuiInterface.cpp.o: geom_api/CMakeFiles/gui_interface_g.dir/flags.make
geom_api/CMakeFiles/gui_interface_g.dir/GuiInterface.cpp.o: /Users/Bruno/OpenVSP-python3/OpenVSP/repo/src/geom_api/GuiInterface.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Bruno/OpenVSP-python3/OpenVSP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object geom_api/CMakeFiles/gui_interface_g.dir/GuiInterface.cpp.o"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/build/geom_api && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gui_interface_g.dir/GuiInterface.cpp.o -c /Users/Bruno/OpenVSP-python3/OpenVSP/repo/src/geom_api/GuiInterface.cpp

geom_api/CMakeFiles/gui_interface_g.dir/GuiInterface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gui_interface_g.dir/GuiInterface.cpp.i"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/build/geom_api && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Bruno/OpenVSP-python3/OpenVSP/repo/src/geom_api/GuiInterface.cpp > CMakeFiles/gui_interface_g.dir/GuiInterface.cpp.i

geom_api/CMakeFiles/gui_interface_g.dir/GuiInterface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gui_interface_g.dir/GuiInterface.cpp.s"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/build/geom_api && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Bruno/OpenVSP-python3/OpenVSP/repo/src/geom_api/GuiInterface.cpp -o CMakeFiles/gui_interface_g.dir/GuiInterface.cpp.s

geom_api/CMakeFiles/gui_interface_g.dir/GuiInterface.cpp.o.requires:

.PHONY : geom_api/CMakeFiles/gui_interface_g.dir/GuiInterface.cpp.o.requires

geom_api/CMakeFiles/gui_interface_g.dir/GuiInterface.cpp.o.provides: geom_api/CMakeFiles/gui_interface_g.dir/GuiInterface.cpp.o.requires
	$(MAKE) -f geom_api/CMakeFiles/gui_interface_g.dir/build.make geom_api/CMakeFiles/gui_interface_g.dir/GuiInterface.cpp.o.provides.build
.PHONY : geom_api/CMakeFiles/gui_interface_g.dir/GuiInterface.cpp.o.provides

geom_api/CMakeFiles/gui_interface_g.dir/GuiInterface.cpp.o.provides.build: geom_api/CMakeFiles/gui_interface_g.dir/GuiInterface.cpp.o


# Object files for target gui_interface_g
gui_interface_g_OBJECTS = \
"CMakeFiles/gui_interface_g.dir/GuiInterface.cpp.o"

# External object files for target gui_interface_g
gui_interface_g_EXTERNAL_OBJECTS =

geom_api/libgui_interface_g.a: geom_api/CMakeFiles/gui_interface_g.dir/GuiInterface.cpp.o
geom_api/libgui_interface_g.a: geom_api/CMakeFiles/gui_interface_g.dir/build.make
geom_api/libgui_interface_g.a: geom_api/CMakeFiles/gui_interface_g.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Bruno/OpenVSP-python3/OpenVSP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libgui_interface_g.a"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/build/geom_api && $(CMAKE_COMMAND) -P CMakeFiles/gui_interface_g.dir/cmake_clean_target.cmake
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/build/geom_api && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gui_interface_g.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
geom_api/CMakeFiles/gui_interface_g.dir/build: geom_api/libgui_interface_g.a

.PHONY : geom_api/CMakeFiles/gui_interface_g.dir/build

geom_api/CMakeFiles/gui_interface_g.dir/requires: geom_api/CMakeFiles/gui_interface_g.dir/GuiInterface.cpp.o.requires

.PHONY : geom_api/CMakeFiles/gui_interface_g.dir/requires

geom_api/CMakeFiles/gui_interface_g.dir/clean:
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/build/geom_api && $(CMAKE_COMMAND) -P CMakeFiles/gui_interface_g.dir/cmake_clean.cmake
.PHONY : geom_api/CMakeFiles/gui_interface_g.dir/clean

geom_api/CMakeFiles/gui_interface_g.dir/depend:
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Bruno/OpenVSP-python3/OpenVSP/repo/src /Users/Bruno/OpenVSP-python3/OpenVSP/repo/src/geom_api /Users/Bruno/OpenVSP-python3/OpenVSP/build /Users/Bruno/OpenVSP-python3/OpenVSP/build/geom_api /Users/Bruno/OpenVSP-python3/OpenVSP/build/geom_api/CMakeFiles/gui_interface_g.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : geom_api/CMakeFiles/gui_interface_g.dir/depend

