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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/hicham/projet/Raytracer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hicham/projet/Raytracer

# Include any dependencies generated for this target.
include CMakeFiles/tests/test_gui_WindowModel.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tests/test_gui_WindowModel.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tests/test_gui_WindowModel.dir/flags.make

CMakeFiles/tests/test_gui_WindowModel.dir/src/gui/tests/test_gui_WindowModel.cpp.o: CMakeFiles/tests/test_gui_WindowModel.dir/flags.make
CMakeFiles/tests/test_gui_WindowModel.dir/src/gui/tests/test_gui_WindowModel.cpp.o: src/gui/tests/test_gui_WindowModel.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/hicham/projet/Raytracer/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/tests/test_gui_WindowModel.dir/src/gui/tests/test_gui_WindowModel.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/tests/test_gui_WindowModel.dir/src/gui/tests/test_gui_WindowModel.cpp.o -c /home/hicham/projet/Raytracer/src/gui/tests/test_gui_WindowModel.cpp

CMakeFiles/tests/test_gui_WindowModel.dir/src/gui/tests/test_gui_WindowModel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests/test_gui_WindowModel.dir/src/gui/tests/test_gui_WindowModel.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/hicham/projet/Raytracer/src/gui/tests/test_gui_WindowModel.cpp > CMakeFiles/tests/test_gui_WindowModel.dir/src/gui/tests/test_gui_WindowModel.cpp.i

CMakeFiles/tests/test_gui_WindowModel.dir/src/gui/tests/test_gui_WindowModel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests/test_gui_WindowModel.dir/src/gui/tests/test_gui_WindowModel.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/hicham/projet/Raytracer/src/gui/tests/test_gui_WindowModel.cpp -o CMakeFiles/tests/test_gui_WindowModel.dir/src/gui/tests/test_gui_WindowModel.cpp.s

CMakeFiles/tests/test_gui_WindowModel.dir/src/gui/tests/test_gui_WindowModel.cpp.o.requires:
.PHONY : CMakeFiles/tests/test_gui_WindowModel.dir/src/gui/tests/test_gui_WindowModel.cpp.o.requires

CMakeFiles/tests/test_gui_WindowModel.dir/src/gui/tests/test_gui_WindowModel.cpp.o.provides: CMakeFiles/tests/test_gui_WindowModel.dir/src/gui/tests/test_gui_WindowModel.cpp.o.requires
	$(MAKE) -f CMakeFiles/tests/test_gui_WindowModel.dir/build.make CMakeFiles/tests/test_gui_WindowModel.dir/src/gui/tests/test_gui_WindowModel.cpp.o.provides.build
.PHONY : CMakeFiles/tests/test_gui_WindowModel.dir/src/gui/tests/test_gui_WindowModel.cpp.o.provides

CMakeFiles/tests/test_gui_WindowModel.dir/src/gui/tests/test_gui_WindowModel.cpp.o.provides.build: CMakeFiles/tests/test_gui_WindowModel.dir/src/gui/tests/test_gui_WindowModel.cpp.o

# Object files for target tests/test_gui_WindowModel
tests/test_gui_WindowModel_OBJECTS = \
"CMakeFiles/tests/test_gui_WindowModel.dir/src/gui/tests/test_gui_WindowModel.cpp.o"

# External object files for target tests/test_gui_WindowModel
tests/test_gui_WindowModel_EXTERNAL_OBJECTS =

build/tests/test_gui_WindowModel: CMakeFiles/tests/test_gui_WindowModel.dir/src/gui/tests/test_gui_WindowModel.cpp.o
build/tests/test_gui_WindowModel: CMakeFiles/tests/test_gui_WindowModel.dir/build.make
build/tests/test_gui_WindowModel: lib/libraytracer_src_lib.so
build/tests/test_gui_WindowModel: /usr/lib/x86_64-linux-gnu/libGLU.so
build/tests/test_gui_WindowModel: /usr/lib/x86_64-linux-gnu/libGL.so
build/tests/test_gui_WindowModel: /usr/lib/x86_64-linux-gnu/libSM.so
build/tests/test_gui_WindowModel: /usr/lib/x86_64-linux-gnu/libICE.so
build/tests/test_gui_WindowModel: /usr/lib/x86_64-linux-gnu/libX11.so
build/tests/test_gui_WindowModel: /usr/lib/x86_64-linux-gnu/libXext.so
build/tests/test_gui_WindowModel: /usr/local/lib/libsfml-system.so
build/tests/test_gui_WindowModel: /usr/local/lib/libsfml-window.so
build/tests/test_gui_WindowModel: /usr/local/lib/libsfml-graphics.so
build/tests/test_gui_WindowModel: CMakeFiles/tests/test_gui_WindowModel.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable build/tests/test_gui_WindowModel"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tests/test_gui_WindowModel.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tests/test_gui_WindowModel.dir/build: build/tests/test_gui_WindowModel
.PHONY : CMakeFiles/tests/test_gui_WindowModel.dir/build

CMakeFiles/tests/test_gui_WindowModel.dir/requires: CMakeFiles/tests/test_gui_WindowModel.dir/src/gui/tests/test_gui_WindowModel.cpp.o.requires
.PHONY : CMakeFiles/tests/test_gui_WindowModel.dir/requires

CMakeFiles/tests/test_gui_WindowModel.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tests/test_gui_WindowModel.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tests/test_gui_WindowModel.dir/clean

CMakeFiles/tests/test_gui_WindowModel.dir/depend:
	cd /home/hicham/projet/Raytracer && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hicham/projet/Raytracer /home/hicham/projet/Raytracer /home/hicham/projet/Raytracer /home/hicham/projet/Raytracer /home/hicham/projet/Raytracer/CMakeFiles/tests/test_gui_WindowModel.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tests/test_gui_WindowModel.dir/depend

