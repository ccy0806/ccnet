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
CMAKE_SOURCE_DIR = /home/guestcc/share/ccnet-log/ccnet

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/guestcc/share/ccnet-log/ccnet

# Include any dependencies generated for this target.
include CMakeFiles/AsyncLog_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/AsyncLog_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AsyncLog_test.dir/flags.make

CMakeFiles/AsyncLog_test.dir/src/test/AsyncLog_test.cpp.o: CMakeFiles/AsyncLog_test.dir/flags.make
CMakeFiles/AsyncLog_test.dir/src/test/AsyncLog_test.cpp.o: src/test/AsyncLog_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guestcc/share/ccnet-log/ccnet/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/AsyncLog_test.dir/src/test/AsyncLog_test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AsyncLog_test.dir/src/test/AsyncLog_test.cpp.o -c /home/guestcc/share/ccnet-log/ccnet/src/test/AsyncLog_test.cpp

CMakeFiles/AsyncLog_test.dir/src/test/AsyncLog_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AsyncLog_test.dir/src/test/AsyncLog_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guestcc/share/ccnet-log/ccnet/src/test/AsyncLog_test.cpp > CMakeFiles/AsyncLog_test.dir/src/test/AsyncLog_test.cpp.i

CMakeFiles/AsyncLog_test.dir/src/test/AsyncLog_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AsyncLog_test.dir/src/test/AsyncLog_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guestcc/share/ccnet-log/ccnet/src/test/AsyncLog_test.cpp -o CMakeFiles/AsyncLog_test.dir/src/test/AsyncLog_test.cpp.s

CMakeFiles/AsyncLog_test.dir/src/base/Logger.cpp.o: CMakeFiles/AsyncLog_test.dir/flags.make
CMakeFiles/AsyncLog_test.dir/src/base/Logger.cpp.o: src/base/Logger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guestcc/share/ccnet-log/ccnet/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/AsyncLog_test.dir/src/base/Logger.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AsyncLog_test.dir/src/base/Logger.cpp.o -c /home/guestcc/share/ccnet-log/ccnet/src/base/Logger.cpp

CMakeFiles/AsyncLog_test.dir/src/base/Logger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AsyncLog_test.dir/src/base/Logger.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guestcc/share/ccnet-log/ccnet/src/base/Logger.cpp > CMakeFiles/AsyncLog_test.dir/src/base/Logger.cpp.i

CMakeFiles/AsyncLog_test.dir/src/base/Logger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AsyncLog_test.dir/src/base/Logger.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guestcc/share/ccnet-log/ccnet/src/base/Logger.cpp -o CMakeFiles/AsyncLog_test.dir/src/base/Logger.cpp.s

CMakeFiles/AsyncLog_test.dir/src/base/Timestamp.cpp.o: CMakeFiles/AsyncLog_test.dir/flags.make
CMakeFiles/AsyncLog_test.dir/src/base/Timestamp.cpp.o: src/base/Timestamp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guestcc/share/ccnet-log/ccnet/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/AsyncLog_test.dir/src/base/Timestamp.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AsyncLog_test.dir/src/base/Timestamp.cpp.o -c /home/guestcc/share/ccnet-log/ccnet/src/base/Timestamp.cpp

CMakeFiles/AsyncLog_test.dir/src/base/Timestamp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AsyncLog_test.dir/src/base/Timestamp.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guestcc/share/ccnet-log/ccnet/src/base/Timestamp.cpp > CMakeFiles/AsyncLog_test.dir/src/base/Timestamp.cpp.i

CMakeFiles/AsyncLog_test.dir/src/base/Timestamp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AsyncLog_test.dir/src/base/Timestamp.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guestcc/share/ccnet-log/ccnet/src/base/Timestamp.cpp -o CMakeFiles/AsyncLog_test.dir/src/base/Timestamp.cpp.s

# Object files for target AsyncLog_test
AsyncLog_test_OBJECTS = \
"CMakeFiles/AsyncLog_test.dir/src/test/AsyncLog_test.cpp.o" \
"CMakeFiles/AsyncLog_test.dir/src/base/Logger.cpp.o" \
"CMakeFiles/AsyncLog_test.dir/src/base/Timestamp.cpp.o"

# External object files for target AsyncLog_test
AsyncLog_test_EXTERNAL_OBJECTS =

bin/AsyncLog_test: CMakeFiles/AsyncLog_test.dir/src/test/AsyncLog_test.cpp.o
bin/AsyncLog_test: CMakeFiles/AsyncLog_test.dir/src/base/Logger.cpp.o
bin/AsyncLog_test: CMakeFiles/AsyncLog_test.dir/src/base/Timestamp.cpp.o
bin/AsyncLog_test: CMakeFiles/AsyncLog_test.dir/build.make
bin/AsyncLog_test: CMakeFiles/AsyncLog_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/guestcc/share/ccnet-log/ccnet/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable bin/AsyncLog_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AsyncLog_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AsyncLog_test.dir/build: bin/AsyncLog_test

.PHONY : CMakeFiles/AsyncLog_test.dir/build

CMakeFiles/AsyncLog_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/AsyncLog_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/AsyncLog_test.dir/clean

CMakeFiles/AsyncLog_test.dir/depend:
	cd /home/guestcc/share/ccnet-log/ccnet && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/guestcc/share/ccnet-log/ccnet /home/guestcc/share/ccnet-log/ccnet /home/guestcc/share/ccnet-log/ccnet /home/guestcc/share/ccnet-log/ccnet /home/guestcc/share/ccnet-log/ccnet/CMakeFiles/AsyncLog_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/AsyncLog_test.dir/depend
