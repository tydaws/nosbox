# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /snap/clion/124/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/124/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/eld/CLionProjects/nosbox-c

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/eld/CLionProjects/nosbox-c/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/nosbox_c.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/nosbox_c.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/nosbox_c.dir/flags.make

CMakeFiles/nosbox_c.dir/src/nitrosh.c.o: CMakeFiles/nosbox_c.dir/flags.make
CMakeFiles/nosbox_c.dir/src/nitrosh.c.o: ../src/nitrosh.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eld/CLionProjects/nosbox-c/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/nosbox_c.dir/src/nitrosh.c.o"
	/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/nosbox_c.dir/src/nitrosh.c.o   -c /home/eld/CLionProjects/nosbox-c/src/nitrosh.c

CMakeFiles/nosbox_c.dir/src/nitrosh.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/nosbox_c.dir/src/nitrosh.c.i"
	/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/eld/CLionProjects/nosbox-c/src/nitrosh.c > CMakeFiles/nosbox_c.dir/src/nitrosh.c.i

CMakeFiles/nosbox_c.dir/src/nitrosh.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/nosbox_c.dir/src/nitrosh.c.s"
	/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/eld/CLionProjects/nosbox-c/src/nitrosh.c -o CMakeFiles/nosbox_c.dir/src/nitrosh.c.s

CMakeFiles/nosbox_c.dir/src/nitrorepo.c.o: CMakeFiles/nosbox_c.dir/flags.make
CMakeFiles/nosbox_c.dir/src/nitrorepo.c.o: ../src/nitrorepo.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eld/CLionProjects/nosbox-c/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/nosbox_c.dir/src/nitrorepo.c.o"
	/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/nosbox_c.dir/src/nitrorepo.c.o   -c /home/eld/CLionProjects/nosbox-c/src/nitrorepo.c

CMakeFiles/nosbox_c.dir/src/nitrorepo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/nosbox_c.dir/src/nitrorepo.c.i"
	/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/eld/CLionProjects/nosbox-c/src/nitrorepo.c > CMakeFiles/nosbox_c.dir/src/nitrorepo.c.i

CMakeFiles/nosbox_c.dir/src/nitrorepo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/nosbox_c.dir/src/nitrorepo.c.s"
	/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/eld/CLionProjects/nosbox-c/src/nitrorepo.c -o CMakeFiles/nosbox_c.dir/src/nitrorepo.c.s

# Object files for target nosbox_c
nosbox_c_OBJECTS = \
"CMakeFiles/nosbox_c.dir/src/nitrosh.c.o" \
"CMakeFiles/nosbox_c.dir/src/nitrorepo.c.o"

# External object files for target nosbox_c
nosbox_c_EXTERNAL_OBJECTS =

nosbox_c: CMakeFiles/nosbox_c.dir/src/nitrosh.c.o
nosbox_c: CMakeFiles/nosbox_c.dir/src/nitrorepo.c.o
nosbox_c: CMakeFiles/nosbox_c.dir/build.make
nosbox_c: CMakeFiles/nosbox_c.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/eld/CLionProjects/nosbox-c/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable nosbox_c"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/nosbox_c.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/nosbox_c.dir/build: nosbox_c

.PHONY : CMakeFiles/nosbox_c.dir/build

CMakeFiles/nosbox_c.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/nosbox_c.dir/cmake_clean.cmake
.PHONY : CMakeFiles/nosbox_c.dir/clean

CMakeFiles/nosbox_c.dir/depend:
	cd /home/eld/CLionProjects/nosbox-c/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/eld/CLionProjects/nosbox-c /home/eld/CLionProjects/nosbox-c /home/eld/CLionProjects/nosbox-c/cmake-build-debug /home/eld/CLionProjects/nosbox-c/cmake-build-debug /home/eld/CLionProjects/nosbox-c/cmake-build-debug/CMakeFiles/nosbox_c.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/nosbox_c.dir/depend
