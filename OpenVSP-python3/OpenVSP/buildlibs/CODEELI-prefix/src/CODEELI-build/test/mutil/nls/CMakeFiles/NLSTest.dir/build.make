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
include test/mutil/nls/CMakeFiles/NLSTest.dir/depend.make

# Include the progress variables for this target.
include test/mutil/nls/CMakeFiles/NLSTest.dir/progress.make

# Include the compile flags for this target's objects.
include test/mutil/nls/CMakeFiles/NLSTest.dir/flags.make

test/mutil/nls/CMakeFiles/NLSTest.dir/nls_test.cpp.o: test/mutil/nls/CMakeFiles/NLSTest.dir/flags.make
test/mutil/nls/CMakeFiles/NLSTest.dir/nls_test.cpp.o: /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI/test/mutil/nls/nls_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/mutil/nls/CMakeFiles/NLSTest.dir/nls_test.cpp.o"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI-build/test/mutil/nls && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NLSTest.dir/nls_test.cpp.o -c /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI/test/mutil/nls/nls_test.cpp

test/mutil/nls/CMakeFiles/NLSTest.dir/nls_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NLSTest.dir/nls_test.cpp.i"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI-build/test/mutil/nls && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI/test/mutil/nls/nls_test.cpp > CMakeFiles/NLSTest.dir/nls_test.cpp.i

test/mutil/nls/CMakeFiles/NLSTest.dir/nls_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NLSTest.dir/nls_test.cpp.s"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI-build/test/mutil/nls && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI/test/mutil/nls/nls_test.cpp -o CMakeFiles/NLSTest.dir/nls_test.cpp.s

test/mutil/nls/CMakeFiles/NLSTest.dir/nls_test.cpp.o.requires:

.PHONY : test/mutil/nls/CMakeFiles/NLSTest.dir/nls_test.cpp.o.requires

test/mutil/nls/CMakeFiles/NLSTest.dir/nls_test.cpp.o.provides: test/mutil/nls/CMakeFiles/NLSTest.dir/nls_test.cpp.o.requires
	$(MAKE) -f test/mutil/nls/CMakeFiles/NLSTest.dir/build.make test/mutil/nls/CMakeFiles/NLSTest.dir/nls_test.cpp.o.provides.build
.PHONY : test/mutil/nls/CMakeFiles/NLSTest.dir/nls_test.cpp.o.provides

test/mutil/nls/CMakeFiles/NLSTest.dir/nls_test.cpp.o.provides.build: test/mutil/nls/CMakeFiles/NLSTest.dir/nls_test.cpp.o


# Object files for target NLSTest
NLSTest_OBJECTS = \
"CMakeFiles/NLSTest.dir/nls_test.cpp.o"

# External object files for target NLSTest
NLSTest_EXTERNAL_OBJECTS =

test/mutil/nls/NLSTest: test/mutil/nls/CMakeFiles/NLSTest.dir/nls_test.cpp.o
test/mutil/nls/NLSTest: test/mutil/nls/CMakeFiles/NLSTest.dir/build.make
test/mutil/nls/NLSTest: /usr/local/lib/libcpptest.dylib
test/mutil/nls/NLSTest: test/mutil/nls/CMakeFiles/NLSTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable NLSTest"
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI-build/test/mutil/nls && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/NLSTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/mutil/nls/CMakeFiles/NLSTest.dir/build: test/mutil/nls/NLSTest

.PHONY : test/mutil/nls/CMakeFiles/NLSTest.dir/build

test/mutil/nls/CMakeFiles/NLSTest.dir/requires: test/mutil/nls/CMakeFiles/NLSTest.dir/nls_test.cpp.o.requires

.PHONY : test/mutil/nls/CMakeFiles/NLSTest.dir/requires

test/mutil/nls/CMakeFiles/NLSTest.dir/clean:
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI-build/test/mutil/nls && $(CMAKE_COMMAND) -P CMakeFiles/NLSTest.dir/cmake_clean.cmake
.PHONY : test/mutil/nls/CMakeFiles/NLSTest.dir/clean

test/mutil/nls/CMakeFiles/NLSTest.dir/depend:
	cd /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI/test/mutil/nls /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI-build /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI-build/test/mutil/nls /Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/CODEELI-prefix/src/CODEELI-build/test/mutil/nls/CMakeFiles/NLSTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/mutil/nls/CMakeFiles/NLSTest.dir/depend

