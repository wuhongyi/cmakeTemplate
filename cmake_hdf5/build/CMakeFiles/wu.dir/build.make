# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/local/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/wu/桌面/hdf5_cmake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wu/桌面/hdf5_cmake/build

# Include any dependencies generated for this target.
include CMakeFiles/wu.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/wu.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/wu.dir/flags.make

CMakeFiles/wu.dir/writedata.cpp.o: CMakeFiles/wu.dir/flags.make
CMakeFiles/wu.dir/writedata.cpp.o: ../writedata.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/wu/桌面/hdf5_cmake/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/wu.dir/writedata.cpp.o"
	/usr/local/bin/g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/wu.dir/writedata.cpp.o -c /home/wu/桌面/hdf5_cmake/writedata.cpp

CMakeFiles/wu.dir/writedata.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wu.dir/writedata.cpp.i"
	/usr/local/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/wu/桌面/hdf5_cmake/writedata.cpp > CMakeFiles/wu.dir/writedata.cpp.i

CMakeFiles/wu.dir/writedata.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wu.dir/writedata.cpp.s"
	/usr/local/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/wu/桌面/hdf5_cmake/writedata.cpp -o CMakeFiles/wu.dir/writedata.cpp.s

CMakeFiles/wu.dir/writedata.cpp.o.requires:
.PHONY : CMakeFiles/wu.dir/writedata.cpp.o.requires

CMakeFiles/wu.dir/writedata.cpp.o.provides: CMakeFiles/wu.dir/writedata.cpp.o.requires
	$(MAKE) -f CMakeFiles/wu.dir/build.make CMakeFiles/wu.dir/writedata.cpp.o.provides.build
.PHONY : CMakeFiles/wu.dir/writedata.cpp.o.provides

CMakeFiles/wu.dir/writedata.cpp.o.provides.build: CMakeFiles/wu.dir/writedata.cpp.o

# Object files for target wu
wu_OBJECTS = \
"CMakeFiles/wu.dir/writedata.cpp.o"

# External object files for target wu
wu_EXTERNAL_OBJECTS =

wu: CMakeFiles/wu.dir/writedata.cpp.o
wu: CMakeFiles/wu.dir/build.make
wu: /usr/lib64/libhdf5.so
wu: /usr/lib64/libhdf5_cpp.so
wu: /usr/lib64/libhdf5.so.7
wu: /usr/lib64/libhdf5_cpp.so.7
wu: /usr/lib64/libhdf5_hl.so
wu: /usr/lib64/libhdf5_hl.so.7
wu: /usr/lib64/libhdf5_hl_cpp.so
wu: /usr/lib64/libhdf5_hl_cpp.so.7
wu: CMakeFiles/wu.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable wu"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/wu.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/wu.dir/build: wu
.PHONY : CMakeFiles/wu.dir/build

CMakeFiles/wu.dir/requires: CMakeFiles/wu.dir/writedata.cpp.o.requires
.PHONY : CMakeFiles/wu.dir/requires

CMakeFiles/wu.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/wu.dir/cmake_clean.cmake
.PHONY : CMakeFiles/wu.dir/clean

CMakeFiles/wu.dir/depend:
	cd /home/wu/桌面/hdf5_cmake/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wu/桌面/hdf5_cmake /home/wu/桌面/hdf5_cmake /home/wu/桌面/hdf5_cmake/build /home/wu/桌面/hdf5_cmake/build /home/wu/桌面/hdf5_cmake/build/CMakeFiles/wu.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/wu.dir/depend

