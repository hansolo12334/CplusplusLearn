# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_SOURCE_DIR = /home/hansolo/CplusplusLearn/交叉编译/zlib-1.2.10

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hansolo/CplusplusLearn/交叉编译/zlib-1.2.10/build

# Include any dependencies generated for this target.
include CMakeFiles/minigzip.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/minigzip.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/minigzip.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/minigzip.dir/flags.make

CMakeFiles/minigzip.dir/test/minigzip.o: CMakeFiles/minigzip.dir/flags.make
CMakeFiles/minigzip.dir/test/minigzip.o: /home/hansolo/CplusplusLearn/交叉编译/zlib-1.2.10/test/minigzip.c
CMakeFiles/minigzip.dir/test/minigzip.o: CMakeFiles/minigzip.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hansolo/CplusplusLearn/交叉编译/zlib-1.2.10/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/minigzip.dir/test/minigzip.o"
	/usr/bin/aarch64-linux-gnu-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/minigzip.dir/test/minigzip.o -MF CMakeFiles/minigzip.dir/test/minigzip.o.d -o CMakeFiles/minigzip.dir/test/minigzip.o -c /home/hansolo/CplusplusLearn/交叉编译/zlib-1.2.10/test/minigzip.c

CMakeFiles/minigzip.dir/test/minigzip.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minigzip.dir/test/minigzip.i"
	/usr/bin/aarch64-linux-gnu-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/hansolo/CplusplusLearn/交叉编译/zlib-1.2.10/test/minigzip.c > CMakeFiles/minigzip.dir/test/minigzip.i

CMakeFiles/minigzip.dir/test/minigzip.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minigzip.dir/test/minigzip.s"
	/usr/bin/aarch64-linux-gnu-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/hansolo/CplusplusLearn/交叉编译/zlib-1.2.10/test/minigzip.c -o CMakeFiles/minigzip.dir/test/minigzip.s

# Object files for target minigzip
minigzip_OBJECTS = \
"CMakeFiles/minigzip.dir/test/minigzip.o"

# External object files for target minigzip
minigzip_EXTERNAL_OBJECTS =

minigzip: CMakeFiles/minigzip.dir/test/minigzip.o
minigzip: CMakeFiles/minigzip.dir/build.make
minigzip: libz.so.1.2.10
minigzip: CMakeFiles/minigzip.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hansolo/CplusplusLearn/交叉编译/zlib-1.2.10/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable minigzip"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/minigzip.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/minigzip.dir/build: minigzip
.PHONY : CMakeFiles/minigzip.dir/build

CMakeFiles/minigzip.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/minigzip.dir/cmake_clean.cmake
.PHONY : CMakeFiles/minigzip.dir/clean

CMakeFiles/minigzip.dir/depend:
	cd /home/hansolo/CplusplusLearn/交叉编译/zlib-1.2.10/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hansolo/CplusplusLearn/交叉编译/zlib-1.2.10 /home/hansolo/CplusplusLearn/交叉编译/zlib-1.2.10 /home/hansolo/CplusplusLearn/交叉编译/zlib-1.2.10/build /home/hansolo/CplusplusLearn/交叉编译/zlib-1.2.10/build /home/hansolo/CplusplusLearn/交叉编译/zlib-1.2.10/build/CMakeFiles/minigzip.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/minigzip.dir/depend

