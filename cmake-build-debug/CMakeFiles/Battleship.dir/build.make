# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\fvall\CLionProjects\Battleship\Battleship

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\fvall\CLionProjects\Battleship\Battleship\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Battleship.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Battleship.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Battleship.dir/flags.make

CMakeFiles/Battleship.dir/main.c.obj: CMakeFiles/Battleship.dir/flags.make
CMakeFiles/Battleship.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\fvall\CLionProjects\Battleship\Battleship\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Battleship.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Battleship.dir\main.c.obj   -c C:\Users\fvall\CLionProjects\Battleship\Battleship\main.c

CMakeFiles/Battleship.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Battleship.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\fvall\CLionProjects\Battleship\Battleship\main.c > CMakeFiles\Battleship.dir\main.c.i

CMakeFiles/Battleship.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Battleship.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\fvall\CLionProjects\Battleship\Battleship\main.c -o CMakeFiles\Battleship.dir\main.c.s

# Object files for target Battleship
Battleship_OBJECTS = \
"CMakeFiles/Battleship.dir/main.c.obj"

# External object files for target Battleship
Battleship_EXTERNAL_OBJECTS =

Battleship.exe: CMakeFiles/Battleship.dir/main.c.obj
Battleship.exe: CMakeFiles/Battleship.dir/build.make
Battleship.exe: CMakeFiles/Battleship.dir/linklibs.rsp
Battleship.exe: CMakeFiles/Battleship.dir/objects1.rsp
Battleship.exe: CMakeFiles/Battleship.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\fvall\CLionProjects\Battleship\Battleship\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Battleship.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Battleship.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Battleship.dir/build: Battleship.exe

.PHONY : CMakeFiles/Battleship.dir/build

CMakeFiles/Battleship.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Battleship.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Battleship.dir/clean

CMakeFiles/Battleship.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\fvall\CLionProjects\Battleship\Battleship C:\Users\fvall\CLionProjects\Battleship\Battleship C:\Users\fvall\CLionProjects\Battleship\Battleship\cmake-build-debug C:\Users\fvall\CLionProjects\Battleship\Battleship\cmake-build-debug C:\Users\fvall\CLionProjects\Battleship\Battleship\cmake-build-debug\CMakeFiles\Battleship.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Battleship.dir/depend

