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
CMAKE_SOURCE_DIR = /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build

# Include any dependencies generated for this target.
include src/cldai/CMakeFiles/stepdai-static.dir/depend.make

# Include the progress variables for this target.
include src/cldai/CMakeFiles/stepdai-static.dir/progress.make

# Include the compile flags for this target's objects.
include src/cldai/CMakeFiles/stepdai-static.dir/flags.make

src/cldai/CMakeFiles/stepdai-static.dir/sdaiApplication_instance_set.cc.o: src/cldai/CMakeFiles/stepdai-static.dir/flags.make
src/cldai/CMakeFiles/stepdai-static.dir/sdaiApplication_instance_set.cc.o: /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/src/cldai/sdaiApplication_instance_set.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/cldai/CMakeFiles/stepdai-static.dir/sdaiApplication_instance_set.cc.o"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/src/cldai && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stepdai-static.dir/sdaiApplication_instance_set.cc.o -c /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/src/cldai/sdaiApplication_instance_set.cc

src/cldai/CMakeFiles/stepdai-static.dir/sdaiApplication_instance_set.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stepdai-static.dir/sdaiApplication_instance_set.cc.i"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/src/cldai && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/src/cldai/sdaiApplication_instance_set.cc > CMakeFiles/stepdai-static.dir/sdaiApplication_instance_set.cc.i

src/cldai/CMakeFiles/stepdai-static.dir/sdaiApplication_instance_set.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stepdai-static.dir/sdaiApplication_instance_set.cc.s"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/src/cldai && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/src/cldai/sdaiApplication_instance_set.cc -o CMakeFiles/stepdai-static.dir/sdaiApplication_instance_set.cc.s

src/cldai/CMakeFiles/stepdai-static.dir/sdaiApplication_instance_set.cc.o.requires:

.PHONY : src/cldai/CMakeFiles/stepdai-static.dir/sdaiApplication_instance_set.cc.o.requires

src/cldai/CMakeFiles/stepdai-static.dir/sdaiApplication_instance_set.cc.o.provides: src/cldai/CMakeFiles/stepdai-static.dir/sdaiApplication_instance_set.cc.o.requires
	$(MAKE) -f src/cldai/CMakeFiles/stepdai-static.dir/build.make src/cldai/CMakeFiles/stepdai-static.dir/sdaiApplication_instance_set.cc.o.provides.build
.PHONY : src/cldai/CMakeFiles/stepdai-static.dir/sdaiApplication_instance_set.cc.o.provides

src/cldai/CMakeFiles/stepdai-static.dir/sdaiApplication_instance_set.cc.o.provides.build: src/cldai/CMakeFiles/stepdai-static.dir/sdaiApplication_instance_set.cc.o


src/cldai/CMakeFiles/stepdai-static.dir/sdaiBinary.cc.o: src/cldai/CMakeFiles/stepdai-static.dir/flags.make
src/cldai/CMakeFiles/stepdai-static.dir/sdaiBinary.cc.o: /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/src/cldai/sdaiBinary.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/cldai/CMakeFiles/stepdai-static.dir/sdaiBinary.cc.o"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/src/cldai && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stepdai-static.dir/sdaiBinary.cc.o -c /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/src/cldai/sdaiBinary.cc

src/cldai/CMakeFiles/stepdai-static.dir/sdaiBinary.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stepdai-static.dir/sdaiBinary.cc.i"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/src/cldai && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/src/cldai/sdaiBinary.cc > CMakeFiles/stepdai-static.dir/sdaiBinary.cc.i

src/cldai/CMakeFiles/stepdai-static.dir/sdaiBinary.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stepdai-static.dir/sdaiBinary.cc.s"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/src/cldai && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/src/cldai/sdaiBinary.cc -o CMakeFiles/stepdai-static.dir/sdaiBinary.cc.s

src/cldai/CMakeFiles/stepdai-static.dir/sdaiBinary.cc.o.requires:

.PHONY : src/cldai/CMakeFiles/stepdai-static.dir/sdaiBinary.cc.o.requires

src/cldai/CMakeFiles/stepdai-static.dir/sdaiBinary.cc.o.provides: src/cldai/CMakeFiles/stepdai-static.dir/sdaiBinary.cc.o.requires
	$(MAKE) -f src/cldai/CMakeFiles/stepdai-static.dir/build.make src/cldai/CMakeFiles/stepdai-static.dir/sdaiBinary.cc.o.provides.build
.PHONY : src/cldai/CMakeFiles/stepdai-static.dir/sdaiBinary.cc.o.provides

src/cldai/CMakeFiles/stepdai-static.dir/sdaiBinary.cc.o.provides.build: src/cldai/CMakeFiles/stepdai-static.dir/sdaiBinary.cc.o


src/cldai/CMakeFiles/stepdai-static.dir/sdaiDaObject.cc.o: src/cldai/CMakeFiles/stepdai-static.dir/flags.make
src/cldai/CMakeFiles/stepdai-static.dir/sdaiDaObject.cc.o: /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/src/cldai/sdaiDaObject.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/cldai/CMakeFiles/stepdai-static.dir/sdaiDaObject.cc.o"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/src/cldai && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stepdai-static.dir/sdaiDaObject.cc.o -c /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/src/cldai/sdaiDaObject.cc

src/cldai/CMakeFiles/stepdai-static.dir/sdaiDaObject.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stepdai-static.dir/sdaiDaObject.cc.i"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/src/cldai && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/src/cldai/sdaiDaObject.cc > CMakeFiles/stepdai-static.dir/sdaiDaObject.cc.i

src/cldai/CMakeFiles/stepdai-static.dir/sdaiDaObject.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stepdai-static.dir/sdaiDaObject.cc.s"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/src/cldai && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/src/cldai/sdaiDaObject.cc -o CMakeFiles/stepdai-static.dir/sdaiDaObject.cc.s

src/cldai/CMakeFiles/stepdai-static.dir/sdaiDaObject.cc.o.requires:

.PHONY : src/cldai/CMakeFiles/stepdai-static.dir/sdaiDaObject.cc.o.requires

src/cldai/CMakeFiles/stepdai-static.dir/sdaiDaObject.cc.o.provides: src/cldai/CMakeFiles/stepdai-static.dir/sdaiDaObject.cc.o.requires
	$(MAKE) -f src/cldai/CMakeFiles/stepdai-static.dir/build.make src/cldai/CMakeFiles/stepdai-static.dir/sdaiDaObject.cc.o.provides.build
.PHONY : src/cldai/CMakeFiles/stepdai-static.dir/sdaiDaObject.cc.o.provides

src/cldai/CMakeFiles/stepdai-static.dir/sdaiDaObject.cc.o.provides.build: src/cldai/CMakeFiles/stepdai-static.dir/sdaiDaObject.cc.o


src/cldai/CMakeFiles/stepdai-static.dir/sdaiEntity_extent.cc.o: src/cldai/CMakeFiles/stepdai-static.dir/flags.make
src/cldai/CMakeFiles/stepdai-static.dir/sdaiEntity_extent.cc.o: /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/src/cldai/sdaiEntity_extent.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/cldai/CMakeFiles/stepdai-static.dir/sdaiEntity_extent.cc.o"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/src/cldai && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stepdai-static.dir/sdaiEntity_extent.cc.o -c /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/src/cldai/sdaiEntity_extent.cc

src/cldai/CMakeFiles/stepdai-static.dir/sdaiEntity_extent.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stepdai-static.dir/sdaiEntity_extent.cc.i"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/src/cldai && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/src/cldai/sdaiEntity_extent.cc > CMakeFiles/stepdai-static.dir/sdaiEntity_extent.cc.i

src/cldai/CMakeFiles/stepdai-static.dir/sdaiEntity_extent.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stepdai-static.dir/sdaiEntity_extent.cc.s"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/src/cldai && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/src/cldai/sdaiEntity_extent.cc -o CMakeFiles/stepdai-static.dir/sdaiEntity_extent.cc.s

src/cldai/CMakeFiles/stepdai-static.dir/sdaiEntity_extent.cc.o.requires:

.PHONY : src/cldai/CMakeFiles/stepdai-static.dir/sdaiEntity_extent.cc.o.requires

src/cldai/CMakeFiles/stepdai-static.dir/sdaiEntity_extent.cc.o.provides: src/cldai/CMakeFiles/stepdai-static.dir/sdaiEntity_extent.cc.o.requires
	$(MAKE) -f src/cldai/CMakeFiles/stepdai-static.dir/build.make src/cldai/CMakeFiles/stepdai-static.dir/sdaiEntity_extent.cc.o.provides.build
.PHONY : src/cldai/CMakeFiles/stepdai-static.dir/sdaiEntity_extent.cc.o.provides

src/cldai/CMakeFiles/stepdai-static.dir/sdaiEntity_extent.cc.o.provides.build: src/cldai/CMakeFiles/stepdai-static.dir/sdaiEntity_extent.cc.o


src/cldai/CMakeFiles/stepdai-static.dir/sdaiEntity_extent_set.cc.o: src/cldai/CMakeFiles/stepdai-static.dir/flags.make
src/cldai/CMakeFiles/stepdai-static.dir/sdaiEntity_extent_set.cc.o: /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/src/cldai/sdaiEntity_extent_set.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/cldai/CMakeFiles/stepdai-static.dir/sdaiEntity_extent_set.cc.o"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/src/cldai && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stepdai-static.dir/sdaiEntity_extent_set.cc.o -c /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/src/cldai/sdaiEntity_extent_set.cc

src/cldai/CMakeFiles/stepdai-static.dir/sdaiEntity_extent_set.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stepdai-static.dir/sdaiEntity_extent_set.cc.i"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/src/cldai && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/src/cldai/sdaiEntity_extent_set.cc > CMakeFiles/stepdai-static.dir/sdaiEntity_extent_set.cc.i

src/cldai/CMakeFiles/stepdai-static.dir/sdaiEntity_extent_set.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stepdai-static.dir/sdaiEntity_extent_set.cc.s"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/src/cldai && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/src/cldai/sdaiEntity_extent_set.cc -o CMakeFiles/stepdai-static.dir/sdaiEntity_extent_set.cc.s

src/cldai/CMakeFiles/stepdai-static.dir/sdaiEntity_extent_set.cc.o.requires:

.PHONY : src/cldai/CMakeFiles/stepdai-static.dir/sdaiEntity_extent_set.cc.o.requires

src/cldai/CMakeFiles/stepdai-static.dir/sdaiEntity_extent_set.cc.o.provides: src/cldai/CMakeFiles/stepdai-static.dir/sdaiEntity_extent_set.cc.o.requires
	$(MAKE) -f src/cldai/CMakeFiles/stepdai-static.dir/build.make src/cldai/CMakeFiles/stepdai-static.dir/sdaiEntity_extent_set.cc.o.provides.build
.PHONY : src/cldai/CMakeFiles/stepdai-static.dir/sdaiEntity_extent_set.cc.o.provides

src/cldai/CMakeFiles/stepdai-static.dir/sdaiEntity_extent_set.cc.o.provides.build: src/cldai/CMakeFiles/stepdai-static.dir/sdaiEntity_extent_set.cc.o


src/cldai/CMakeFiles/stepdai-static.dir/sdaiEnum.cc.o: src/cldai/CMakeFiles/stepdai-static.dir/flags.make
src/cldai/CMakeFiles/stepdai-static.dir/sdaiEnum.cc.o: /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/src/cldai/sdaiEnum.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/cldai/CMakeFiles/stepdai-static.dir/sdaiEnum.cc.o"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/src/cldai && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stepdai-static.dir/sdaiEnum.cc.o -c /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/src/cldai/sdaiEnum.cc

src/cldai/CMakeFiles/stepdai-static.dir/sdaiEnum.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stepdai-static.dir/sdaiEnum.cc.i"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/src/cldai && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/src/cldai/sdaiEnum.cc > CMakeFiles/stepdai-static.dir/sdaiEnum.cc.i

src/cldai/CMakeFiles/stepdai-static.dir/sdaiEnum.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stepdai-static.dir/sdaiEnum.cc.s"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/src/cldai && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/src/cldai/sdaiEnum.cc -o CMakeFiles/stepdai-static.dir/sdaiEnum.cc.s

src/cldai/CMakeFiles/stepdai-static.dir/sdaiEnum.cc.o.requires:

.PHONY : src/cldai/CMakeFiles/stepdai-static.dir/sdaiEnum.cc.o.requires

src/cldai/CMakeFiles/stepdai-static.dir/sdaiEnum.cc.o.provides: src/cldai/CMakeFiles/stepdai-static.dir/sdaiEnum.cc.o.requires
	$(MAKE) -f src/cldai/CMakeFiles/stepdai-static.dir/build.make src/cldai/CMakeFiles/stepdai-static.dir/sdaiEnum.cc.o.provides.build
.PHONY : src/cldai/CMakeFiles/stepdai-static.dir/sdaiEnum.cc.o.provides

src/cldai/CMakeFiles/stepdai-static.dir/sdaiEnum.cc.o.provides.build: src/cldai/CMakeFiles/stepdai-static.dir/sdaiEnum.cc.o


src/cldai/CMakeFiles/stepdai-static.dir/sdaiModel_contents.cc.o: src/cldai/CMakeFiles/stepdai-static.dir/flags.make
src/cldai/CMakeFiles/stepdai-static.dir/sdaiModel_contents.cc.o: /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/src/cldai/sdaiModel_contents.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/cldai/CMakeFiles/stepdai-static.dir/sdaiModel_contents.cc.o"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/src/cldai && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stepdai-static.dir/sdaiModel_contents.cc.o -c /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/src/cldai/sdaiModel_contents.cc

src/cldai/CMakeFiles/stepdai-static.dir/sdaiModel_contents.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stepdai-static.dir/sdaiModel_contents.cc.i"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/src/cldai && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/src/cldai/sdaiModel_contents.cc > CMakeFiles/stepdai-static.dir/sdaiModel_contents.cc.i

src/cldai/CMakeFiles/stepdai-static.dir/sdaiModel_contents.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stepdai-static.dir/sdaiModel_contents.cc.s"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/src/cldai && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/src/cldai/sdaiModel_contents.cc -o CMakeFiles/stepdai-static.dir/sdaiModel_contents.cc.s

src/cldai/CMakeFiles/stepdai-static.dir/sdaiModel_contents.cc.o.requires:

.PHONY : src/cldai/CMakeFiles/stepdai-static.dir/sdaiModel_contents.cc.o.requires

src/cldai/CMakeFiles/stepdai-static.dir/sdaiModel_contents.cc.o.provides: src/cldai/CMakeFiles/stepdai-static.dir/sdaiModel_contents.cc.o.requires
	$(MAKE) -f src/cldai/CMakeFiles/stepdai-static.dir/build.make src/cldai/CMakeFiles/stepdai-static.dir/sdaiModel_contents.cc.o.provides.build
.PHONY : src/cldai/CMakeFiles/stepdai-static.dir/sdaiModel_contents.cc.o.provides

src/cldai/CMakeFiles/stepdai-static.dir/sdaiModel_contents.cc.o.provides.build: src/cldai/CMakeFiles/stepdai-static.dir/sdaiModel_contents.cc.o


src/cldai/CMakeFiles/stepdai-static.dir/sdaiModel_contents_list.cc.o: src/cldai/CMakeFiles/stepdai-static.dir/flags.make
src/cldai/CMakeFiles/stepdai-static.dir/sdaiModel_contents_list.cc.o: /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/src/cldai/sdaiModel_contents_list.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object src/cldai/CMakeFiles/stepdai-static.dir/sdaiModel_contents_list.cc.o"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/src/cldai && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stepdai-static.dir/sdaiModel_contents_list.cc.o -c /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/src/cldai/sdaiModel_contents_list.cc

src/cldai/CMakeFiles/stepdai-static.dir/sdaiModel_contents_list.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stepdai-static.dir/sdaiModel_contents_list.cc.i"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/src/cldai && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/src/cldai/sdaiModel_contents_list.cc > CMakeFiles/stepdai-static.dir/sdaiModel_contents_list.cc.i

src/cldai/CMakeFiles/stepdai-static.dir/sdaiModel_contents_list.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stepdai-static.dir/sdaiModel_contents_list.cc.s"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/src/cldai && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/src/cldai/sdaiModel_contents_list.cc -o CMakeFiles/stepdai-static.dir/sdaiModel_contents_list.cc.s

src/cldai/CMakeFiles/stepdai-static.dir/sdaiModel_contents_list.cc.o.requires:

.PHONY : src/cldai/CMakeFiles/stepdai-static.dir/sdaiModel_contents_list.cc.o.requires

src/cldai/CMakeFiles/stepdai-static.dir/sdaiModel_contents_list.cc.o.provides: src/cldai/CMakeFiles/stepdai-static.dir/sdaiModel_contents_list.cc.o.requires
	$(MAKE) -f src/cldai/CMakeFiles/stepdai-static.dir/build.make src/cldai/CMakeFiles/stepdai-static.dir/sdaiModel_contents_list.cc.o.provides.build
.PHONY : src/cldai/CMakeFiles/stepdai-static.dir/sdaiModel_contents_list.cc.o.provides

src/cldai/CMakeFiles/stepdai-static.dir/sdaiModel_contents_list.cc.o.provides.build: src/cldai/CMakeFiles/stepdai-static.dir/sdaiModel_contents_list.cc.o


src/cldai/CMakeFiles/stepdai-static.dir/sdaiObject.cc.o: src/cldai/CMakeFiles/stepdai-static.dir/flags.make
src/cldai/CMakeFiles/stepdai-static.dir/sdaiObject.cc.o: /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/src/cldai/sdaiObject.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object src/cldai/CMakeFiles/stepdai-static.dir/sdaiObject.cc.o"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/src/cldai && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stepdai-static.dir/sdaiObject.cc.o -c /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/src/cldai/sdaiObject.cc

src/cldai/CMakeFiles/stepdai-static.dir/sdaiObject.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stepdai-static.dir/sdaiObject.cc.i"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/src/cldai && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/src/cldai/sdaiObject.cc > CMakeFiles/stepdai-static.dir/sdaiObject.cc.i

src/cldai/CMakeFiles/stepdai-static.dir/sdaiObject.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stepdai-static.dir/sdaiObject.cc.s"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/src/cldai && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/src/cldai/sdaiObject.cc -o CMakeFiles/stepdai-static.dir/sdaiObject.cc.s

src/cldai/CMakeFiles/stepdai-static.dir/sdaiObject.cc.o.requires:

.PHONY : src/cldai/CMakeFiles/stepdai-static.dir/sdaiObject.cc.o.requires

src/cldai/CMakeFiles/stepdai-static.dir/sdaiObject.cc.o.provides: src/cldai/CMakeFiles/stepdai-static.dir/sdaiObject.cc.o.requires
	$(MAKE) -f src/cldai/CMakeFiles/stepdai-static.dir/build.make src/cldai/CMakeFiles/stepdai-static.dir/sdaiObject.cc.o.provides.build
.PHONY : src/cldai/CMakeFiles/stepdai-static.dir/sdaiObject.cc.o.provides

src/cldai/CMakeFiles/stepdai-static.dir/sdaiObject.cc.o.provides.build: src/cldai/CMakeFiles/stepdai-static.dir/sdaiObject.cc.o


src/cldai/CMakeFiles/stepdai-static.dir/sdaiSession_instance.cc.o: src/cldai/CMakeFiles/stepdai-static.dir/flags.make
src/cldai/CMakeFiles/stepdai-static.dir/sdaiSession_instance.cc.o: /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/src/cldai/sdaiSession_instance.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object src/cldai/CMakeFiles/stepdai-static.dir/sdaiSession_instance.cc.o"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/src/cldai && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stepdai-static.dir/sdaiSession_instance.cc.o -c /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/src/cldai/sdaiSession_instance.cc

src/cldai/CMakeFiles/stepdai-static.dir/sdaiSession_instance.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stepdai-static.dir/sdaiSession_instance.cc.i"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/src/cldai && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/src/cldai/sdaiSession_instance.cc > CMakeFiles/stepdai-static.dir/sdaiSession_instance.cc.i

src/cldai/CMakeFiles/stepdai-static.dir/sdaiSession_instance.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stepdai-static.dir/sdaiSession_instance.cc.s"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/src/cldai && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/src/cldai/sdaiSession_instance.cc -o CMakeFiles/stepdai-static.dir/sdaiSession_instance.cc.s

src/cldai/CMakeFiles/stepdai-static.dir/sdaiSession_instance.cc.o.requires:

.PHONY : src/cldai/CMakeFiles/stepdai-static.dir/sdaiSession_instance.cc.o.requires

src/cldai/CMakeFiles/stepdai-static.dir/sdaiSession_instance.cc.o.provides: src/cldai/CMakeFiles/stepdai-static.dir/sdaiSession_instance.cc.o.requires
	$(MAKE) -f src/cldai/CMakeFiles/stepdai-static.dir/build.make src/cldai/CMakeFiles/stepdai-static.dir/sdaiSession_instance.cc.o.provides.build
.PHONY : src/cldai/CMakeFiles/stepdai-static.dir/sdaiSession_instance.cc.o.provides

src/cldai/CMakeFiles/stepdai-static.dir/sdaiSession_instance.cc.o.provides.build: src/cldai/CMakeFiles/stepdai-static.dir/sdaiSession_instance.cc.o


src/cldai/CMakeFiles/stepdai-static.dir/sdaiString.cc.o: src/cldai/CMakeFiles/stepdai-static.dir/flags.make
src/cldai/CMakeFiles/stepdai-static.dir/sdaiString.cc.o: /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/src/cldai/sdaiString.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object src/cldai/CMakeFiles/stepdai-static.dir/sdaiString.cc.o"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/src/cldai && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stepdai-static.dir/sdaiString.cc.o -c /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/src/cldai/sdaiString.cc

src/cldai/CMakeFiles/stepdai-static.dir/sdaiString.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stepdai-static.dir/sdaiString.cc.i"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/src/cldai && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/src/cldai/sdaiString.cc > CMakeFiles/stepdai-static.dir/sdaiString.cc.i

src/cldai/CMakeFiles/stepdai-static.dir/sdaiString.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stepdai-static.dir/sdaiString.cc.s"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/src/cldai && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/src/cldai/sdaiString.cc -o CMakeFiles/stepdai-static.dir/sdaiString.cc.s

src/cldai/CMakeFiles/stepdai-static.dir/sdaiString.cc.o.requires:

.PHONY : src/cldai/CMakeFiles/stepdai-static.dir/sdaiString.cc.o.requires

src/cldai/CMakeFiles/stepdai-static.dir/sdaiString.cc.o.provides: src/cldai/CMakeFiles/stepdai-static.dir/sdaiString.cc.o.requires
	$(MAKE) -f src/cldai/CMakeFiles/stepdai-static.dir/build.make src/cldai/CMakeFiles/stepdai-static.dir/sdaiString.cc.o.provides.build
.PHONY : src/cldai/CMakeFiles/stepdai-static.dir/sdaiString.cc.o.provides

src/cldai/CMakeFiles/stepdai-static.dir/sdaiString.cc.o.provides.build: src/cldai/CMakeFiles/stepdai-static.dir/sdaiString.cc.o


# Object files for target stepdai-static
stepdai__static_OBJECTS = \
"CMakeFiles/stepdai-static.dir/sdaiApplication_instance_set.cc.o" \
"CMakeFiles/stepdai-static.dir/sdaiBinary.cc.o" \
"CMakeFiles/stepdai-static.dir/sdaiDaObject.cc.o" \
"CMakeFiles/stepdai-static.dir/sdaiEntity_extent.cc.o" \
"CMakeFiles/stepdai-static.dir/sdaiEntity_extent_set.cc.o" \
"CMakeFiles/stepdai-static.dir/sdaiEnum.cc.o" \
"CMakeFiles/stepdai-static.dir/sdaiModel_contents.cc.o" \
"CMakeFiles/stepdai-static.dir/sdaiModel_contents_list.cc.o" \
"CMakeFiles/stepdai-static.dir/sdaiObject.cc.o" \
"CMakeFiles/stepdai-static.dir/sdaiSession_instance.cc.o" \
"CMakeFiles/stepdai-static.dir/sdaiString.cc.o"

# External object files for target stepdai-static
stepdai__static_EXTERNAL_OBJECTS =

lib/libstepdai.a: src/cldai/CMakeFiles/stepdai-static.dir/sdaiApplication_instance_set.cc.o
lib/libstepdai.a: src/cldai/CMakeFiles/stepdai-static.dir/sdaiBinary.cc.o
lib/libstepdai.a: src/cldai/CMakeFiles/stepdai-static.dir/sdaiDaObject.cc.o
lib/libstepdai.a: src/cldai/CMakeFiles/stepdai-static.dir/sdaiEntity_extent.cc.o
lib/libstepdai.a: src/cldai/CMakeFiles/stepdai-static.dir/sdaiEntity_extent_set.cc.o
lib/libstepdai.a: src/cldai/CMakeFiles/stepdai-static.dir/sdaiEnum.cc.o
lib/libstepdai.a: src/cldai/CMakeFiles/stepdai-static.dir/sdaiModel_contents.cc.o
lib/libstepdai.a: src/cldai/CMakeFiles/stepdai-static.dir/sdaiModel_contents_list.cc.o
lib/libstepdai.a: src/cldai/CMakeFiles/stepdai-static.dir/sdaiObject.cc.o
lib/libstepdai.a: src/cldai/CMakeFiles/stepdai-static.dir/sdaiSession_instance.cc.o
lib/libstepdai.a: src/cldai/CMakeFiles/stepdai-static.dir/sdaiString.cc.o
lib/libstepdai.a: src/cldai/CMakeFiles/stepdai-static.dir/build.make
lib/libstepdai.a: src/cldai/CMakeFiles/stepdai-static.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX static library ../../lib/libstepdai.a"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/src/cldai && $(CMAKE_COMMAND) -P CMakeFiles/stepdai-static.dir/cmake_clean_target.cmake
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/src/cldai && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/stepdai-static.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/cldai/CMakeFiles/stepdai-static.dir/build: lib/libstepdai.a

.PHONY : src/cldai/CMakeFiles/stepdai-static.dir/build

src/cldai/CMakeFiles/stepdai-static.dir/requires: src/cldai/CMakeFiles/stepdai-static.dir/sdaiApplication_instance_set.cc.o.requires
src/cldai/CMakeFiles/stepdai-static.dir/requires: src/cldai/CMakeFiles/stepdai-static.dir/sdaiBinary.cc.o.requires
src/cldai/CMakeFiles/stepdai-static.dir/requires: src/cldai/CMakeFiles/stepdai-static.dir/sdaiDaObject.cc.o.requires
src/cldai/CMakeFiles/stepdai-static.dir/requires: src/cldai/CMakeFiles/stepdai-static.dir/sdaiEntity_extent.cc.o.requires
src/cldai/CMakeFiles/stepdai-static.dir/requires: src/cldai/CMakeFiles/stepdai-static.dir/sdaiEntity_extent_set.cc.o.requires
src/cldai/CMakeFiles/stepdai-static.dir/requires: src/cldai/CMakeFiles/stepdai-static.dir/sdaiEnum.cc.o.requires
src/cldai/CMakeFiles/stepdai-static.dir/requires: src/cldai/CMakeFiles/stepdai-static.dir/sdaiModel_contents.cc.o.requires
src/cldai/CMakeFiles/stepdai-static.dir/requires: src/cldai/CMakeFiles/stepdai-static.dir/sdaiModel_contents_list.cc.o.requires
src/cldai/CMakeFiles/stepdai-static.dir/requires: src/cldai/CMakeFiles/stepdai-static.dir/sdaiObject.cc.o.requires
src/cldai/CMakeFiles/stepdai-static.dir/requires: src/cldai/CMakeFiles/stepdai-static.dir/sdaiSession_instance.cc.o.requires
src/cldai/CMakeFiles/stepdai-static.dir/requires: src/cldai/CMakeFiles/stepdai-static.dir/sdaiString.cc.o.requires

.PHONY : src/cldai/CMakeFiles/stepdai-static.dir/requires

src/cldai/CMakeFiles/stepdai-static.dir/clean:
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/src/cldai && $(CMAKE_COMMAND) -P CMakeFiles/stepdai-static.dir/cmake_clean.cmake
.PHONY : src/cldai/CMakeFiles/stepdai-static.dir/clean

src/cldai/CMakeFiles/stepdai-static.dir/depend:
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/src/cldai /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/src/cldai /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE-build/src/cldai/CMakeFiles/stepdai-static.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/cldai/CMakeFiles/stepdai-static.dir/depend
