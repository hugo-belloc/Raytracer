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
CMAKE_SOURCE_DIR = /home/hicham/Desktop/ensi/s4/projet/Raytracer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hicham/Desktop/ensi/s4/projet/Raytracer

# Include any dependencies generated for this target.
include CMakeFiles/raytracer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/raytracer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/raytracer.dir/flags.make

CMakeFiles/raytracer.dir/src/main/main.cpp.o: CMakeFiles/raytracer.dir/flags.make
CMakeFiles/raytracer.dir/src/main/main.cpp.o: src/main/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/hicham/Desktop/ensi/s4/projet/Raytracer/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/raytracer.dir/src/main/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/raytracer.dir/src/main/main.cpp.o -c /home/hicham/Desktop/ensi/s4/projet/Raytracer/src/main/main.cpp

CMakeFiles/raytracer.dir/src/main/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/raytracer.dir/src/main/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/hicham/Desktop/ensi/s4/projet/Raytracer/src/main/main.cpp > CMakeFiles/raytracer.dir/src/main/main.cpp.i

CMakeFiles/raytracer.dir/src/main/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/raytracer.dir/src/main/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/hicham/Desktop/ensi/s4/projet/Raytracer/src/main/main.cpp -o CMakeFiles/raytracer.dir/src/main/main.cpp.s

CMakeFiles/raytracer.dir/src/main/main.cpp.o.requires:
.PHONY : CMakeFiles/raytracer.dir/src/main/main.cpp.o.requires

CMakeFiles/raytracer.dir/src/main/main.cpp.o.provides: CMakeFiles/raytracer.dir/src/main/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/raytracer.dir/build.make CMakeFiles/raytracer.dir/src/main/main.cpp.o.provides.build
.PHONY : CMakeFiles/raytracer.dir/src/main/main.cpp.o.provides

CMakeFiles/raytracer.dir/src/main/main.cpp.o.provides.build: CMakeFiles/raytracer.dir/src/main/main.cpp.o

# Object files for target raytracer
raytracer_OBJECTS = \
"CMakeFiles/raytracer.dir/src/main/main.cpp.o"

# External object files for target raytracer
raytracer_EXTERNAL_OBJECTS =

build/raytracer: CMakeFiles/raytracer.dir/src/main/main.cpp.o
build/raytracer: CMakeFiles/raytracer.dir/build.make
build/raytracer: lib/libraytracer_src_lib.a
build/raytracer: /usr/lib/x86_64-linux-gnu/libGLU.so
build/raytracer: /usr/lib/x86_64-linux-gnu/libGL.so
build/raytracer: /usr/lib/x86_64-linux-gnu/libSM.so
build/raytracer: /usr/lib/x86_64-linux-gnu/libICE.so
build/raytracer: /usr/lib/x86_64-linux-gnu/libX11.so
build/raytracer: /usr/lib/x86_64-linux-gnu/libXext.so
build/raytracer: /usr/local/lib/libsfml-system.so
build/raytracer: /usr/local/lib/libsfml-window.so
build/raytracer: /usr/local/lib/libsfml-graphics.so
build/raytracer: CMakeFiles/raytracer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable build/raytracer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/raytracer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/raytracer.dir/build: build/raytracer
.PHONY : CMakeFiles/raytracer.dir/build

CMakeFiles/raytracer.dir/requires: CMakeFiles/raytracer.dir/src/main/main.cpp.o.requires
.PHONY : CMakeFiles/raytracer.dir/requires

CMakeFiles/raytracer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/raytracer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/raytracer.dir/clean

CMakeFiles/raytracer.dir/depend:
	cd /home/hicham/Desktop/ensi/s4/projet/Raytracer && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hicham/Desktop/ensi/s4/projet/Raytracer /home/hicham/Desktop/ensi/s4/projet/Raytracer /home/hicham/Desktop/ensi/s4/projet/Raytracer /home/hicham/Desktop/ensi/s4/projet/Raytracer /home/hicham/Desktop/ensi/s4/projet/Raytracer/CMakeFiles/raytracer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/raytracer.dir/depend

