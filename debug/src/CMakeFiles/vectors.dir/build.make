# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.24.2/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.24.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ben/Documents/gitrepos/Rotating_ASCII_Cube

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ben/Documents/gitrepos/Rotating_ASCII_Cube/debug

# Include any dependencies generated for this target.
include src/CMakeFiles/vectors.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/vectors.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/vectors.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/vectors.dir/flags.make

src/CMakeFiles/vectors.dir/vector.c.o: src/CMakeFiles/vectors.dir/flags.make
src/CMakeFiles/vectors.dir/vector.c.o: /Users/ben/Documents/gitrepos/Rotating_ASCII_Cube/src/vector.c
src/CMakeFiles/vectors.dir/vector.c.o: src/CMakeFiles/vectors.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ben/Documents/gitrepos/Rotating_ASCII_Cube/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/CMakeFiles/vectors.dir/vector.c.o"
	cd /Users/ben/Documents/gitrepos/Rotating_ASCII_Cube/debug/src && clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/vectors.dir/vector.c.o -MF CMakeFiles/vectors.dir/vector.c.o.d -o CMakeFiles/vectors.dir/vector.c.o -c /Users/ben/Documents/gitrepos/Rotating_ASCII_Cube/src/vector.c

src/CMakeFiles/vectors.dir/vector.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/vectors.dir/vector.c.i"
	cd /Users/ben/Documents/gitrepos/Rotating_ASCII_Cube/debug/src && clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ben/Documents/gitrepos/Rotating_ASCII_Cube/src/vector.c > CMakeFiles/vectors.dir/vector.c.i

src/CMakeFiles/vectors.dir/vector.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/vectors.dir/vector.c.s"
	cd /Users/ben/Documents/gitrepos/Rotating_ASCII_Cube/debug/src && clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ben/Documents/gitrepos/Rotating_ASCII_Cube/src/vector.c -o CMakeFiles/vectors.dir/vector.c.s

# Object files for target vectors
vectors_OBJECTS = \
"CMakeFiles/vectors.dir/vector.c.o"

# External object files for target vectors
vectors_EXTERNAL_OBJECTS =

/Users/ben/Documents/gitrepos/Rotating_ASCII_Cube/libs/libvectors.dylib: src/CMakeFiles/vectors.dir/vector.c.o
/Users/ben/Documents/gitrepos/Rotating_ASCII_Cube/libs/libvectors.dylib: src/CMakeFiles/vectors.dir/build.make
/Users/ben/Documents/gitrepos/Rotating_ASCII_Cube/libs/libvectors.dylib: src/CMakeFiles/vectors.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ben/Documents/gitrepos/Rotating_ASCII_Cube/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library /Users/ben/Documents/gitrepos/Rotating_ASCII_Cube/libs/libvectors.dylib"
	cd /Users/ben/Documents/gitrepos/Rotating_ASCII_Cube/debug/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/vectors.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/vectors.dir/build: /Users/ben/Documents/gitrepos/Rotating_ASCII_Cube/libs/libvectors.dylib
.PHONY : src/CMakeFiles/vectors.dir/build

src/CMakeFiles/vectors.dir/clean:
	cd /Users/ben/Documents/gitrepos/Rotating_ASCII_Cube/debug/src && $(CMAKE_COMMAND) -P CMakeFiles/vectors.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/vectors.dir/clean

src/CMakeFiles/vectors.dir/depend:
	cd /Users/ben/Documents/gitrepos/Rotating_ASCII_Cube/debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ben/Documents/gitrepos/Rotating_ASCII_Cube /Users/ben/Documents/gitrepos/Rotating_ASCII_Cube/src /Users/ben/Documents/gitrepos/Rotating_ASCII_Cube/debug /Users/ben/Documents/gitrepos/Rotating_ASCII_Cube/debug/src /Users/ben/Documents/gitrepos/Rotating_ASCII_Cube/debug/src/CMakeFiles/vectors.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/vectors.dir/depend

