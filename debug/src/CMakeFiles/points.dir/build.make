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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/bena/Documents/gitrepos/Rotating_ASCII_Cube

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bena/Documents/gitrepos/Rotating_ASCII_Cube/debug

# Include any dependencies generated for this target.
include src/CMakeFiles/points.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/points.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/points.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/points.dir/flags.make

src/CMakeFiles/points.dir/point.c.o: src/CMakeFiles/points.dir/flags.make
src/CMakeFiles/points.dir/point.c.o: /home/bena/Documents/gitrepos/Rotating_ASCII_Cube/src/point.c
src/CMakeFiles/points.dir/point.c.o: src/CMakeFiles/points.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bena/Documents/gitrepos/Rotating_ASCII_Cube/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/CMakeFiles/points.dir/point.c.o"
	cd /home/bena/Documents/gitrepos/Rotating_ASCII_Cube/debug/src && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/points.dir/point.c.o -MF CMakeFiles/points.dir/point.c.o.d -o CMakeFiles/points.dir/point.c.o -c /home/bena/Documents/gitrepos/Rotating_ASCII_Cube/src/point.c

src/CMakeFiles/points.dir/point.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/points.dir/point.c.i"
	cd /home/bena/Documents/gitrepos/Rotating_ASCII_Cube/debug/src && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bena/Documents/gitrepos/Rotating_ASCII_Cube/src/point.c > CMakeFiles/points.dir/point.c.i

src/CMakeFiles/points.dir/point.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/points.dir/point.c.s"
	cd /home/bena/Documents/gitrepos/Rotating_ASCII_Cube/debug/src && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bena/Documents/gitrepos/Rotating_ASCII_Cube/src/point.c -o CMakeFiles/points.dir/point.c.s

# Object files for target points
points_OBJECTS = \
"CMakeFiles/points.dir/point.c.o"

# External object files for target points
points_EXTERNAL_OBJECTS =

/home/bena/Documents/gitrepos/Rotating_ASCII_Cube/libs/libpoints.so: src/CMakeFiles/points.dir/point.c.o
/home/bena/Documents/gitrepos/Rotating_ASCII_Cube/libs/libpoints.so: src/CMakeFiles/points.dir/build.make
/home/bena/Documents/gitrepos/Rotating_ASCII_Cube/libs/libpoints.so: src/CMakeFiles/points.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bena/Documents/gitrepos/Rotating_ASCII_Cube/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library /home/bena/Documents/gitrepos/Rotating_ASCII_Cube/libs/libpoints.so"
	cd /home/bena/Documents/gitrepos/Rotating_ASCII_Cube/debug/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/points.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/points.dir/build: /home/bena/Documents/gitrepos/Rotating_ASCII_Cube/libs/libpoints.so
.PHONY : src/CMakeFiles/points.dir/build

src/CMakeFiles/points.dir/clean:
	cd /home/bena/Documents/gitrepos/Rotating_ASCII_Cube/debug/src && $(CMAKE_COMMAND) -P CMakeFiles/points.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/points.dir/clean

src/CMakeFiles/points.dir/depend:
	cd /home/bena/Documents/gitrepos/Rotating_ASCII_Cube/debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bena/Documents/gitrepos/Rotating_ASCII_Cube /home/bena/Documents/gitrepos/Rotating_ASCII_Cube/src /home/bena/Documents/gitrepos/Rotating_ASCII_Cube/debug /home/bena/Documents/gitrepos/Rotating_ASCII_Cube/debug/src /home/bena/Documents/gitrepos/Rotating_ASCII_Cube/debug/src/CMakeFiles/points.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/points.dir/depend
