# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.1\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.1\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\SooYeon Kim\Desktop\CSS 342 A\ass2(2)"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\SooYeon Kim\Desktop\CSS 342 A\ass2(2)\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/ass2_2_.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ass2_2_.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ass2_2_.dir/flags.make

CMakeFiles/ass2_2_.dir/ass2.cpp.obj: CMakeFiles/ass2_2_.dir/flags.make
CMakeFiles/ass2_2_.dir/ass2.cpp.obj: ../ass2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\SooYeon Kim\Desktop\CSS 342 A\ass2(2)\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ass2_2_.dir/ass2.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ass2_2_.dir\ass2.cpp.obj -c "C:\Users\SooYeon Kim\Desktop\CSS 342 A\ass2(2)\ass2.cpp"

CMakeFiles/ass2_2_.dir/ass2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ass2_2_.dir/ass2.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\SooYeon Kim\Desktop\CSS 342 A\ass2(2)\ass2.cpp" > CMakeFiles\ass2_2_.dir\ass2.cpp.i

CMakeFiles/ass2_2_.dir/ass2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ass2_2_.dir/ass2.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\SooYeon Kim\Desktop\CSS 342 A\ass2(2)\ass2.cpp" -o CMakeFiles\ass2_2_.dir\ass2.cpp.s

CMakeFiles/ass2_2_.dir/ass2.cpp.obj.requires:

.PHONY : CMakeFiles/ass2_2_.dir/ass2.cpp.obj.requires

CMakeFiles/ass2_2_.dir/ass2.cpp.obj.provides: CMakeFiles/ass2_2_.dir/ass2.cpp.obj.requires
	$(MAKE) -f CMakeFiles\ass2_2_.dir\build.make CMakeFiles/ass2_2_.dir/ass2.cpp.obj.provides.build
.PHONY : CMakeFiles/ass2_2_.dir/ass2.cpp.obj.provides

CMakeFiles/ass2_2_.dir/ass2.cpp.obj.provides.build: CMakeFiles/ass2_2_.dir/ass2.cpp.obj


CMakeFiles/ass2_2_.dir/timespan.cpp.obj: CMakeFiles/ass2_2_.dir/flags.make
CMakeFiles/ass2_2_.dir/timespan.cpp.obj: ../timespan.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\SooYeon Kim\Desktop\CSS 342 A\ass2(2)\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ass2_2_.dir/timespan.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ass2_2_.dir\timespan.cpp.obj -c "C:\Users\SooYeon Kim\Desktop\CSS 342 A\ass2(2)\timespan.cpp"

CMakeFiles/ass2_2_.dir/timespan.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ass2_2_.dir/timespan.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\SooYeon Kim\Desktop\CSS 342 A\ass2(2)\timespan.cpp" > CMakeFiles\ass2_2_.dir\timespan.cpp.i

CMakeFiles/ass2_2_.dir/timespan.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ass2_2_.dir/timespan.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\SooYeon Kim\Desktop\CSS 342 A\ass2(2)\timespan.cpp" -o CMakeFiles\ass2_2_.dir\timespan.cpp.s

CMakeFiles/ass2_2_.dir/timespan.cpp.obj.requires:

.PHONY : CMakeFiles/ass2_2_.dir/timespan.cpp.obj.requires

CMakeFiles/ass2_2_.dir/timespan.cpp.obj.provides: CMakeFiles/ass2_2_.dir/timespan.cpp.obj.requires
	$(MAKE) -f CMakeFiles\ass2_2_.dir\build.make CMakeFiles/ass2_2_.dir/timespan.cpp.obj.provides.build
.PHONY : CMakeFiles/ass2_2_.dir/timespan.cpp.obj.provides

CMakeFiles/ass2_2_.dir/timespan.cpp.obj.provides.build: CMakeFiles/ass2_2_.dir/timespan.cpp.obj


# Object files for target ass2_2_
ass2_2__OBJECTS = \
"CMakeFiles/ass2_2_.dir/ass2.cpp.obj" \
"CMakeFiles/ass2_2_.dir/timespan.cpp.obj"

# External object files for target ass2_2_
ass2_2__EXTERNAL_OBJECTS =

ass2_2_.exe: CMakeFiles/ass2_2_.dir/ass2.cpp.obj
ass2_2_.exe: CMakeFiles/ass2_2_.dir/timespan.cpp.obj
ass2_2_.exe: CMakeFiles/ass2_2_.dir/build.make
ass2_2_.exe: CMakeFiles/ass2_2_.dir/linklibs.rsp
ass2_2_.exe: CMakeFiles/ass2_2_.dir/objects1.rsp
ass2_2_.exe: CMakeFiles/ass2_2_.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\SooYeon Kim\Desktop\CSS 342 A\ass2(2)\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ass2_2_.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ass2_2_.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ass2_2_.dir/build: ass2_2_.exe

.PHONY : CMakeFiles/ass2_2_.dir/build

CMakeFiles/ass2_2_.dir/requires: CMakeFiles/ass2_2_.dir/ass2.cpp.obj.requires
CMakeFiles/ass2_2_.dir/requires: CMakeFiles/ass2_2_.dir/timespan.cpp.obj.requires

.PHONY : CMakeFiles/ass2_2_.dir/requires

CMakeFiles/ass2_2_.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ass2_2_.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ass2_2_.dir/clean

CMakeFiles/ass2_2_.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\SooYeon Kim\Desktop\CSS 342 A\ass2(2)" "C:\Users\SooYeon Kim\Desktop\CSS 342 A\ass2(2)" "C:\Users\SooYeon Kim\Desktop\CSS 342 A\ass2(2)\cmake-build-debug" "C:\Users\SooYeon Kim\Desktop\CSS 342 A\ass2(2)\cmake-build-debug" "C:\Users\SooYeon Kim\Desktop\CSS 342 A\ass2(2)\cmake-build-debug\CMakeFiles\ass2_2_.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/ass2_2_.dir/depend

