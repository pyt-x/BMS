# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\install_software\Clion\CLion 2020.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\install_software\Clion\CLion 2020.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\My_code\C\BMS

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\My_code\C\BMS\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/BMS.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BMS.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BMS.dir/flags.make

CMakeFiles/BMS.dir/main.c.obj: CMakeFiles/BMS.dir/flags.make
CMakeFiles/BMS.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\My_code\C\BMS\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/BMS.dir/main.c.obj"
	D:\install_software\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\BMS.dir\main.c.obj   -c D:\My_code\C\BMS\main.c

CMakeFiles/BMS.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/BMS.dir/main.c.i"
	D:\install_software\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\My_code\C\BMS\main.c > CMakeFiles\BMS.dir\main.c.i

CMakeFiles/BMS.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/BMS.dir/main.c.s"
	D:\install_software\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\My_code\C\BMS\main.c -o CMakeFiles\BMS.dir\main.c.s

CMakeFiles/BMS.dir/manage.c.obj: CMakeFiles/BMS.dir/flags.make
CMakeFiles/BMS.dir/manage.c.obj: ../manage.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\My_code\C\BMS\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/BMS.dir/manage.c.obj"
	D:\install_software\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\BMS.dir\manage.c.obj   -c D:\My_code\C\BMS\manage.c

CMakeFiles/BMS.dir/manage.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/BMS.dir/manage.c.i"
	D:\install_software\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\My_code\C\BMS\manage.c > CMakeFiles\BMS.dir\manage.c.i

CMakeFiles/BMS.dir/manage.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/BMS.dir/manage.c.s"
	D:\install_software\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\My_code\C\BMS\manage.c -o CMakeFiles\BMS.dir\manage.c.s

CMakeFiles/BMS.dir/book.c.obj: CMakeFiles/BMS.dir/flags.make
CMakeFiles/BMS.dir/book.c.obj: ../book.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\My_code\C\BMS\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/BMS.dir/book.c.obj"
	D:\install_software\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\BMS.dir\book.c.obj   -c D:\My_code\C\BMS\book.c

CMakeFiles/BMS.dir/book.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/BMS.dir/book.c.i"
	D:\install_software\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\My_code\C\BMS\book.c > CMakeFiles\BMS.dir\book.c.i

CMakeFiles/BMS.dir/book.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/BMS.dir/book.c.s"
	D:\install_software\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\My_code\C\BMS\book.c -o CMakeFiles\BMS.dir\book.c.s

CMakeFiles/BMS.dir/penalty.c.obj: CMakeFiles/BMS.dir/flags.make
CMakeFiles/BMS.dir/penalty.c.obj: ../penalty.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\My_code\C\BMS\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/BMS.dir/penalty.c.obj"
	D:\install_software\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\BMS.dir\penalty.c.obj   -c D:\My_code\C\BMS\penalty.c

CMakeFiles/BMS.dir/penalty.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/BMS.dir/penalty.c.i"
	D:\install_software\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\My_code\C\BMS\penalty.c > CMakeFiles\BMS.dir\penalty.c.i

CMakeFiles/BMS.dir/penalty.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/BMS.dir/penalty.c.s"
	D:\install_software\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\My_code\C\BMS\penalty.c -o CMakeFiles\BMS.dir\penalty.c.s

CMakeFiles/BMS.dir/register_login.c.obj: CMakeFiles/BMS.dir/flags.make
CMakeFiles/BMS.dir/register_login.c.obj: ../register_login.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\My_code\C\BMS\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/BMS.dir/register_login.c.obj"
	D:\install_software\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\BMS.dir\register_login.c.obj   -c D:\My_code\C\BMS\register_login.c

CMakeFiles/BMS.dir/register_login.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/BMS.dir/register_login.c.i"
	D:\install_software\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\My_code\C\BMS\register_login.c > CMakeFiles\BMS.dir\register_login.c.i

CMakeFiles/BMS.dir/register_login.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/BMS.dir/register_login.c.s"
	D:\install_software\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\My_code\C\BMS\register_login.c -o CMakeFiles\BMS.dir\register_login.c.s

CMakeFiles/BMS.dir/lend_return.c.obj: CMakeFiles/BMS.dir/flags.make
CMakeFiles/BMS.dir/lend_return.c.obj: ../lend_return.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\My_code\C\BMS\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/BMS.dir/lend_return.c.obj"
	D:\install_software\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\BMS.dir\lend_return.c.obj   -c D:\My_code\C\BMS\lend_return.c

CMakeFiles/BMS.dir/lend_return.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/BMS.dir/lend_return.c.i"
	D:\install_software\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\My_code\C\BMS\lend_return.c > CMakeFiles\BMS.dir\lend_return.c.i

CMakeFiles/BMS.dir/lend_return.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/BMS.dir/lend_return.c.s"
	D:\install_software\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\My_code\C\BMS\lend_return.c -o CMakeFiles\BMS.dir\lend_return.c.s

# Object files for target BMS
BMS_OBJECTS = \
"CMakeFiles/BMS.dir/main.c.obj" \
"CMakeFiles/BMS.dir/manage.c.obj" \
"CMakeFiles/BMS.dir/book.c.obj" \
"CMakeFiles/BMS.dir/penalty.c.obj" \
"CMakeFiles/BMS.dir/register_login.c.obj" \
"CMakeFiles/BMS.dir/lend_return.c.obj"

# External object files for target BMS
BMS_EXTERNAL_OBJECTS =

BMS.exe: CMakeFiles/BMS.dir/main.c.obj
BMS.exe: CMakeFiles/BMS.dir/manage.c.obj
BMS.exe: CMakeFiles/BMS.dir/book.c.obj
BMS.exe: CMakeFiles/BMS.dir/penalty.c.obj
BMS.exe: CMakeFiles/BMS.dir/register_login.c.obj
BMS.exe: CMakeFiles/BMS.dir/lend_return.c.obj
BMS.exe: CMakeFiles/BMS.dir/build.make
BMS.exe: CMakeFiles/BMS.dir/linklibs.rsp
BMS.exe: CMakeFiles/BMS.dir/objects1.rsp
BMS.exe: CMakeFiles/BMS.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\My_code\C\BMS\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable BMS.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\BMS.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BMS.dir/build: BMS.exe

.PHONY : CMakeFiles/BMS.dir/build

CMakeFiles/BMS.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\BMS.dir\cmake_clean.cmake
.PHONY : CMakeFiles/BMS.dir/clean

CMakeFiles/BMS.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\My_code\C\BMS D:\My_code\C\BMS D:\My_code\C\BMS\cmake-build-debug D:\My_code\C\BMS\cmake-build-debug D:\My_code\C\BMS\cmake-build-debug\CMakeFiles\BMS.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BMS.dir/depend

