# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/guestcc/share/ccnet

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/guestcc/share/ccnet/build

# Include any dependencies generated for this target.
include CMakeFiles/ccnet.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ccnet.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ccnet.dir/flags.make

CMakeFiles/ccnet.dir/src/base/Threadpool.cpp.o: CMakeFiles/ccnet.dir/flags.make
CMakeFiles/ccnet.dir/src/base/Threadpool.cpp.o: ../src/base/Threadpool.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guestcc/share/ccnet/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ccnet.dir/src/base/Threadpool.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ccnet.dir/src/base/Threadpool.cpp.o -c /home/guestcc/share/ccnet/src/base/Threadpool.cpp

CMakeFiles/ccnet.dir/src/base/Threadpool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ccnet.dir/src/base/Threadpool.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guestcc/share/ccnet/src/base/Threadpool.cpp > CMakeFiles/ccnet.dir/src/base/Threadpool.cpp.i

CMakeFiles/ccnet.dir/src/base/Threadpool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ccnet.dir/src/base/Threadpool.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guestcc/share/ccnet/src/base/Threadpool.cpp -o CMakeFiles/ccnet.dir/src/base/Threadpool.cpp.s

# Object files for target ccnet
ccnet_OBJECTS = \
"CMakeFiles/ccnet.dir/src/base/Threadpool.cpp.o"

# External object files for target ccnet
ccnet_EXTERNAL_OBJECTS =

libccnet.so: CMakeFiles/ccnet.dir/src/base/Threadpool.cpp.o
libccnet.so: CMakeFiles/ccnet.dir/build.make
libccnet.so: CMakeFiles/ccnet.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/guestcc/share/ccnet/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libccnet.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ccnet.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ccnet.dir/build: libccnet.so

.PHONY : CMakeFiles/ccnet.dir/build

CMakeFiles/ccnet.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ccnet.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ccnet.dir/clean

CMakeFiles/ccnet.dir/depend:
	cd /home/guestcc/share/ccnet/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/guestcc/share/ccnet /home/guestcc/share/ccnet /home/guestcc/share/ccnet/build /home/guestcc/share/ccnet/build /home/guestcc/share/ccnet/build/CMakeFiles/ccnet.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ccnet.dir/depend

