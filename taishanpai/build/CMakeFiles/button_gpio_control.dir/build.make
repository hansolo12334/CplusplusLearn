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
CMAKE_SOURCE_DIR = /home/hansolo/CplusplusLearn/taishanpai

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hansolo/CplusplusLearn/taishanpai/build

# Include any dependencies generated for this target.
include CMakeFiles/button_gpio_control.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/button_gpio_control.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/button_gpio_control.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/button_gpio_control.dir/flags.make

CMakeFiles/button_gpio_control.dir/src/oled/button_gpio_control.c.o: CMakeFiles/button_gpio_control.dir/flags.make
CMakeFiles/button_gpio_control.dir/src/oled/button_gpio_control.c.o: /home/hansolo/CplusplusLearn/taishanpai/src/oled/button_gpio_control.c
CMakeFiles/button_gpio_control.dir/src/oled/button_gpio_control.c.o: CMakeFiles/button_gpio_control.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hansolo/CplusplusLearn/taishanpai/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/button_gpio_control.dir/src/oled/button_gpio_control.c.o"
	/usr/bin/aarch64-linux-gnu-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/button_gpio_control.dir/src/oled/button_gpio_control.c.o -MF CMakeFiles/button_gpio_control.dir/src/oled/button_gpio_control.c.o.d -o CMakeFiles/button_gpio_control.dir/src/oled/button_gpio_control.c.o -c /home/hansolo/CplusplusLearn/taishanpai/src/oled/button_gpio_control.c

CMakeFiles/button_gpio_control.dir/src/oled/button_gpio_control.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/button_gpio_control.dir/src/oled/button_gpio_control.c.i"
	/usr/bin/aarch64-linux-gnu-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/hansolo/CplusplusLearn/taishanpai/src/oled/button_gpio_control.c > CMakeFiles/button_gpio_control.dir/src/oled/button_gpio_control.c.i

CMakeFiles/button_gpio_control.dir/src/oled/button_gpio_control.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/button_gpio_control.dir/src/oled/button_gpio_control.c.s"
	/usr/bin/aarch64-linux-gnu-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/hansolo/CplusplusLearn/taishanpai/src/oled/button_gpio_control.c -o CMakeFiles/button_gpio_control.dir/src/oled/button_gpio_control.c.s

# Object files for target button_gpio_control
button_gpio_control_OBJECTS = \
"CMakeFiles/button_gpio_control.dir/src/oled/button_gpio_control.c.o"

# External object files for target button_gpio_control
button_gpio_control_EXTERNAL_OBJECTS =

button_gpio_control: CMakeFiles/button_gpio_control.dir/src/oled/button_gpio_control.c.o
button_gpio_control: CMakeFiles/button_gpio_control.dir/build.make
button_gpio_control: CMakeFiles/button_gpio_control.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hansolo/CplusplusLearn/taishanpai/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable button_gpio_control"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/button_gpio_control.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/button_gpio_control.dir/build: button_gpio_control
.PHONY : CMakeFiles/button_gpio_control.dir/build

CMakeFiles/button_gpio_control.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/button_gpio_control.dir/cmake_clean.cmake
.PHONY : CMakeFiles/button_gpio_control.dir/clean

CMakeFiles/button_gpio_control.dir/depend:
	cd /home/hansolo/CplusplusLearn/taishanpai/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hansolo/CplusplusLearn/taishanpai /home/hansolo/CplusplusLearn/taishanpai /home/hansolo/CplusplusLearn/taishanpai/build /home/hansolo/CplusplusLearn/taishanpai/build /home/hansolo/CplusplusLearn/taishanpai/build/CMakeFiles/button_gpio_control.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/button_gpio_control.dir/depend

