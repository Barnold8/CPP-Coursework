# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_SOURCE_DIR = /home/barnold/Code/C++/CPP-Coursework/Project-CW1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/barnold/Code/C++/CPP-Coursework/Project-CW1/build

# Include any dependencies generated for this target.
include CMakeFiles/SDL2_App.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SDL2_App.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SDL2_App.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SDL2_App.dir/flags.make

CMakeFiles/SDL2_App.dir/src/mainfunction.cpp.o: CMakeFiles/SDL2_App.dir/flags.make
CMakeFiles/SDL2_App.dir/src/mainfunction.cpp.o: /home/barnold/Code/C++/CPP-Coursework/Project-CW1/src/mainfunction.cpp
CMakeFiles/SDL2_App.dir/src/mainfunction.cpp.o: CMakeFiles/SDL2_App.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/barnold/Code/C++/CPP-Coursework/Project-CW1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SDL2_App.dir/src/mainfunction.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SDL2_App.dir/src/mainfunction.cpp.o -MF CMakeFiles/SDL2_App.dir/src/mainfunction.cpp.o.d -o CMakeFiles/SDL2_App.dir/src/mainfunction.cpp.o -c /home/barnold/Code/C++/CPP-Coursework/Project-CW1/src/mainfunction.cpp

CMakeFiles/SDL2_App.dir/src/mainfunction.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SDL2_App.dir/src/mainfunction.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/barnold/Code/C++/CPP-Coursework/Project-CW1/src/mainfunction.cpp > CMakeFiles/SDL2_App.dir/src/mainfunction.cpp.i

CMakeFiles/SDL2_App.dir/src/mainfunction.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SDL2_App.dir/src/mainfunction.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/barnold/Code/C++/CPP-Coursework/Project-CW1/src/mainfunction.cpp -o CMakeFiles/SDL2_App.dir/src/mainfunction.cpp.s

CMakeFiles/SDL2_App.dir/src/BaseEngine.cpp.o: CMakeFiles/SDL2_App.dir/flags.make
CMakeFiles/SDL2_App.dir/src/BaseEngine.cpp.o: /home/barnold/Code/C++/CPP-Coursework/Project-CW1/src/BaseEngine.cpp
CMakeFiles/SDL2_App.dir/src/BaseEngine.cpp.o: CMakeFiles/SDL2_App.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/barnold/Code/C++/CPP-Coursework/Project-CW1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SDL2_App.dir/src/BaseEngine.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SDL2_App.dir/src/BaseEngine.cpp.o -MF CMakeFiles/SDL2_App.dir/src/BaseEngine.cpp.o.d -o CMakeFiles/SDL2_App.dir/src/BaseEngine.cpp.o -c /home/barnold/Code/C++/CPP-Coursework/Project-CW1/src/BaseEngine.cpp

CMakeFiles/SDL2_App.dir/src/BaseEngine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SDL2_App.dir/src/BaseEngine.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/barnold/Code/C++/CPP-Coursework/Project-CW1/src/BaseEngine.cpp > CMakeFiles/SDL2_App.dir/src/BaseEngine.cpp.i

CMakeFiles/SDL2_App.dir/src/BaseEngine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SDL2_App.dir/src/BaseEngine.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/barnold/Code/C++/CPP-Coursework/Project-CW1/src/BaseEngine.cpp -o CMakeFiles/SDL2_App.dir/src/BaseEngine.cpp.s

CMakeFiles/SDL2_App.dir/src/DisplayableObject.cpp.o: CMakeFiles/SDL2_App.dir/flags.make
CMakeFiles/SDL2_App.dir/src/DisplayableObject.cpp.o: /home/barnold/Code/C++/CPP-Coursework/Project-CW1/src/DisplayableObject.cpp
CMakeFiles/SDL2_App.dir/src/DisplayableObject.cpp.o: CMakeFiles/SDL2_App.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/barnold/Code/C++/CPP-Coursework/Project-CW1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SDL2_App.dir/src/DisplayableObject.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SDL2_App.dir/src/DisplayableObject.cpp.o -MF CMakeFiles/SDL2_App.dir/src/DisplayableObject.cpp.o.d -o CMakeFiles/SDL2_App.dir/src/DisplayableObject.cpp.o -c /home/barnold/Code/C++/CPP-Coursework/Project-CW1/src/DisplayableObject.cpp

CMakeFiles/SDL2_App.dir/src/DisplayableObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SDL2_App.dir/src/DisplayableObject.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/barnold/Code/C++/CPP-Coursework/Project-CW1/src/DisplayableObject.cpp > CMakeFiles/SDL2_App.dir/src/DisplayableObject.cpp.i

CMakeFiles/SDL2_App.dir/src/DisplayableObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SDL2_App.dir/src/DisplayableObject.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/barnold/Code/C++/CPP-Coursework/Project-CW1/src/DisplayableObject.cpp -o CMakeFiles/SDL2_App.dir/src/DisplayableObject.cpp.s

CMakeFiles/SDL2_App.dir/src/DrawingSurface.cpp.o: CMakeFiles/SDL2_App.dir/flags.make
CMakeFiles/SDL2_App.dir/src/DrawingSurface.cpp.o: /home/barnold/Code/C++/CPP-Coursework/Project-CW1/src/DrawingSurface.cpp
CMakeFiles/SDL2_App.dir/src/DrawingSurface.cpp.o: CMakeFiles/SDL2_App.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/barnold/Code/C++/CPP-Coursework/Project-CW1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/SDL2_App.dir/src/DrawingSurface.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SDL2_App.dir/src/DrawingSurface.cpp.o -MF CMakeFiles/SDL2_App.dir/src/DrawingSurface.cpp.o.d -o CMakeFiles/SDL2_App.dir/src/DrawingSurface.cpp.o -c /home/barnold/Code/C++/CPP-Coursework/Project-CW1/src/DrawingSurface.cpp

CMakeFiles/SDL2_App.dir/src/DrawingSurface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SDL2_App.dir/src/DrawingSurface.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/barnold/Code/C++/CPP-Coursework/Project-CW1/src/DrawingSurface.cpp > CMakeFiles/SDL2_App.dir/src/DrawingSurface.cpp.i

CMakeFiles/SDL2_App.dir/src/DrawingSurface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SDL2_App.dir/src/DrawingSurface.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/barnold/Code/C++/CPP-Coursework/Project-CW1/src/DrawingSurface.cpp -o CMakeFiles/SDL2_App.dir/src/DrawingSurface.cpp.s

CMakeFiles/SDL2_App.dir/src/FontManager.cpp.o: CMakeFiles/SDL2_App.dir/flags.make
CMakeFiles/SDL2_App.dir/src/FontManager.cpp.o: /home/barnold/Code/C++/CPP-Coursework/Project-CW1/src/FontManager.cpp
CMakeFiles/SDL2_App.dir/src/FontManager.cpp.o: CMakeFiles/SDL2_App.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/barnold/Code/C++/CPP-Coursework/Project-CW1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/SDL2_App.dir/src/FontManager.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SDL2_App.dir/src/FontManager.cpp.o -MF CMakeFiles/SDL2_App.dir/src/FontManager.cpp.o.d -o CMakeFiles/SDL2_App.dir/src/FontManager.cpp.o -c /home/barnold/Code/C++/CPP-Coursework/Project-CW1/src/FontManager.cpp

CMakeFiles/SDL2_App.dir/src/FontManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SDL2_App.dir/src/FontManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/barnold/Code/C++/CPP-Coursework/Project-CW1/src/FontManager.cpp > CMakeFiles/SDL2_App.dir/src/FontManager.cpp.i

CMakeFiles/SDL2_App.dir/src/FontManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SDL2_App.dir/src/FontManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/barnold/Code/C++/CPP-Coursework/Project-CW1/src/FontManager.cpp -o CMakeFiles/SDL2_App.dir/src/FontManager.cpp.s

CMakeFiles/SDL2_App.dir/src/SimpleImage.cpp.o: CMakeFiles/SDL2_App.dir/flags.make
CMakeFiles/SDL2_App.dir/src/SimpleImage.cpp.o: /home/barnold/Code/C++/CPP-Coursework/Project-CW1/src/SimpleImage.cpp
CMakeFiles/SDL2_App.dir/src/SimpleImage.cpp.o: CMakeFiles/SDL2_App.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/barnold/Code/C++/CPP-Coursework/Project-CW1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/SDL2_App.dir/src/SimpleImage.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SDL2_App.dir/src/SimpleImage.cpp.o -MF CMakeFiles/SDL2_App.dir/src/SimpleImage.cpp.o.d -o CMakeFiles/SDL2_App.dir/src/SimpleImage.cpp.o -c /home/barnold/Code/C++/CPP-Coursework/Project-CW1/src/SimpleImage.cpp

CMakeFiles/SDL2_App.dir/src/SimpleImage.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SDL2_App.dir/src/SimpleImage.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/barnold/Code/C++/CPP-Coursework/Project-CW1/src/SimpleImage.cpp > CMakeFiles/SDL2_App.dir/src/SimpleImage.cpp.i

CMakeFiles/SDL2_App.dir/src/SimpleImage.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SDL2_App.dir/src/SimpleImage.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/barnold/Code/C++/CPP-Coursework/Project-CW1/src/SimpleImage.cpp -o CMakeFiles/SDL2_App.dir/src/SimpleImage.cpp.s

CMakeFiles/SDL2_App.dir/src/TileManager.cpp.o: CMakeFiles/SDL2_App.dir/flags.make
CMakeFiles/SDL2_App.dir/src/TileManager.cpp.o: /home/barnold/Code/C++/CPP-Coursework/Project-CW1/src/TileManager.cpp
CMakeFiles/SDL2_App.dir/src/TileManager.cpp.o: CMakeFiles/SDL2_App.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/barnold/Code/C++/CPP-Coursework/Project-CW1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/SDL2_App.dir/src/TileManager.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SDL2_App.dir/src/TileManager.cpp.o -MF CMakeFiles/SDL2_App.dir/src/TileManager.cpp.o.d -o CMakeFiles/SDL2_App.dir/src/TileManager.cpp.o -c /home/barnold/Code/C++/CPP-Coursework/Project-CW1/src/TileManager.cpp

CMakeFiles/SDL2_App.dir/src/TileManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SDL2_App.dir/src/TileManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/barnold/Code/C++/CPP-Coursework/Project-CW1/src/TileManager.cpp > CMakeFiles/SDL2_App.dir/src/TileManager.cpp.i

CMakeFiles/SDL2_App.dir/src/TileManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SDL2_App.dir/src/TileManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/barnold/Code/C++/CPP-Coursework/Project-CW1/src/TileManager.cpp -o CMakeFiles/SDL2_App.dir/src/TileManager.cpp.s

CMakeFiles/SDL2_App.dir/ProjectSrc/cw1_main.cpp.o: CMakeFiles/SDL2_App.dir/flags.make
CMakeFiles/SDL2_App.dir/ProjectSrc/cw1_main.cpp.o: /home/barnold/Code/C++/CPP-Coursework/Project-CW1/ProjectSrc/cw1_main.cpp
CMakeFiles/SDL2_App.dir/ProjectSrc/cw1_main.cpp.o: CMakeFiles/SDL2_App.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/barnold/Code/C++/CPP-Coursework/Project-CW1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/SDL2_App.dir/ProjectSrc/cw1_main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SDL2_App.dir/ProjectSrc/cw1_main.cpp.o -MF CMakeFiles/SDL2_App.dir/ProjectSrc/cw1_main.cpp.o.d -o CMakeFiles/SDL2_App.dir/ProjectSrc/cw1_main.cpp.o -c /home/barnold/Code/C++/CPP-Coursework/Project-CW1/ProjectSrc/cw1_main.cpp

CMakeFiles/SDL2_App.dir/ProjectSrc/cw1_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SDL2_App.dir/ProjectSrc/cw1_main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/barnold/Code/C++/CPP-Coursework/Project-CW1/ProjectSrc/cw1_main.cpp > CMakeFiles/SDL2_App.dir/ProjectSrc/cw1_main.cpp.i

CMakeFiles/SDL2_App.dir/ProjectSrc/cw1_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SDL2_App.dir/ProjectSrc/cw1_main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/barnold/Code/C++/CPP-Coursework/Project-CW1/ProjectSrc/cw1_main.cpp -o CMakeFiles/SDL2_App.dir/ProjectSrc/cw1_main.cpp.s

CMakeFiles/SDL2_App.dir/ProjectSrc/Bird.cpp.o: CMakeFiles/SDL2_App.dir/flags.make
CMakeFiles/SDL2_App.dir/ProjectSrc/Bird.cpp.o: /home/barnold/Code/C++/CPP-Coursework/Project-CW1/ProjectSrc/Bird.cpp
CMakeFiles/SDL2_App.dir/ProjectSrc/Bird.cpp.o: CMakeFiles/SDL2_App.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/barnold/Code/C++/CPP-Coursework/Project-CW1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/SDL2_App.dir/ProjectSrc/Bird.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SDL2_App.dir/ProjectSrc/Bird.cpp.o -MF CMakeFiles/SDL2_App.dir/ProjectSrc/Bird.cpp.o.d -o CMakeFiles/SDL2_App.dir/ProjectSrc/Bird.cpp.o -c /home/barnold/Code/C++/CPP-Coursework/Project-CW1/ProjectSrc/Bird.cpp

CMakeFiles/SDL2_App.dir/ProjectSrc/Bird.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SDL2_App.dir/ProjectSrc/Bird.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/barnold/Code/C++/CPP-Coursework/Project-CW1/ProjectSrc/Bird.cpp > CMakeFiles/SDL2_App.dir/ProjectSrc/Bird.cpp.i

CMakeFiles/SDL2_App.dir/ProjectSrc/Bird.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SDL2_App.dir/ProjectSrc/Bird.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/barnold/Code/C++/CPP-Coursework/Project-CW1/ProjectSrc/Bird.cpp -o CMakeFiles/SDL2_App.dir/ProjectSrc/Bird.cpp.s

CMakeFiles/SDL2_App.dir/ProjectSrc/TileMap.cpp.o: CMakeFiles/SDL2_App.dir/flags.make
CMakeFiles/SDL2_App.dir/ProjectSrc/TileMap.cpp.o: /home/barnold/Code/C++/CPP-Coursework/Project-CW1/ProjectSrc/TileMap.cpp
CMakeFiles/SDL2_App.dir/ProjectSrc/TileMap.cpp.o: CMakeFiles/SDL2_App.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/barnold/Code/C++/CPP-Coursework/Project-CW1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/SDL2_App.dir/ProjectSrc/TileMap.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SDL2_App.dir/ProjectSrc/TileMap.cpp.o -MF CMakeFiles/SDL2_App.dir/ProjectSrc/TileMap.cpp.o.d -o CMakeFiles/SDL2_App.dir/ProjectSrc/TileMap.cpp.o -c /home/barnold/Code/C++/CPP-Coursework/Project-CW1/ProjectSrc/TileMap.cpp

CMakeFiles/SDL2_App.dir/ProjectSrc/TileMap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SDL2_App.dir/ProjectSrc/TileMap.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/barnold/Code/C++/CPP-Coursework/Project-CW1/ProjectSrc/TileMap.cpp > CMakeFiles/SDL2_App.dir/ProjectSrc/TileMap.cpp.i

CMakeFiles/SDL2_App.dir/ProjectSrc/TileMap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SDL2_App.dir/ProjectSrc/TileMap.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/barnold/Code/C++/CPP-Coursework/Project-CW1/ProjectSrc/TileMap.cpp -o CMakeFiles/SDL2_App.dir/ProjectSrc/TileMap.cpp.s

CMakeFiles/SDL2_App.dir/ProjectSrc/Pipe.cpp.o: CMakeFiles/SDL2_App.dir/flags.make
CMakeFiles/SDL2_App.dir/ProjectSrc/Pipe.cpp.o: /home/barnold/Code/C++/CPP-Coursework/Project-CW1/ProjectSrc/Pipe.cpp
CMakeFiles/SDL2_App.dir/ProjectSrc/Pipe.cpp.o: CMakeFiles/SDL2_App.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/barnold/Code/C++/CPP-Coursework/Project-CW1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/SDL2_App.dir/ProjectSrc/Pipe.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SDL2_App.dir/ProjectSrc/Pipe.cpp.o -MF CMakeFiles/SDL2_App.dir/ProjectSrc/Pipe.cpp.o.d -o CMakeFiles/SDL2_App.dir/ProjectSrc/Pipe.cpp.o -c /home/barnold/Code/C++/CPP-Coursework/Project-CW1/ProjectSrc/Pipe.cpp

CMakeFiles/SDL2_App.dir/ProjectSrc/Pipe.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SDL2_App.dir/ProjectSrc/Pipe.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/barnold/Code/C++/CPP-Coursework/Project-CW1/ProjectSrc/Pipe.cpp > CMakeFiles/SDL2_App.dir/ProjectSrc/Pipe.cpp.i

CMakeFiles/SDL2_App.dir/ProjectSrc/Pipe.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SDL2_App.dir/ProjectSrc/Pipe.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/barnold/Code/C++/CPP-Coursework/Project-CW1/ProjectSrc/Pipe.cpp -o CMakeFiles/SDL2_App.dir/ProjectSrc/Pipe.cpp.s

CMakeFiles/SDL2_App.dir/ProjectSrc/PipePair.cpp.o: CMakeFiles/SDL2_App.dir/flags.make
CMakeFiles/SDL2_App.dir/ProjectSrc/PipePair.cpp.o: /home/barnold/Code/C++/CPP-Coursework/Project-CW1/ProjectSrc/PipePair.cpp
CMakeFiles/SDL2_App.dir/ProjectSrc/PipePair.cpp.o: CMakeFiles/SDL2_App.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/barnold/Code/C++/CPP-Coursework/Project-CW1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/SDL2_App.dir/ProjectSrc/PipePair.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SDL2_App.dir/ProjectSrc/PipePair.cpp.o -MF CMakeFiles/SDL2_App.dir/ProjectSrc/PipePair.cpp.o.d -o CMakeFiles/SDL2_App.dir/ProjectSrc/PipePair.cpp.o -c /home/barnold/Code/C++/CPP-Coursework/Project-CW1/ProjectSrc/PipePair.cpp

CMakeFiles/SDL2_App.dir/ProjectSrc/PipePair.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SDL2_App.dir/ProjectSrc/PipePair.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/barnold/Code/C++/CPP-Coursework/Project-CW1/ProjectSrc/PipePair.cpp > CMakeFiles/SDL2_App.dir/ProjectSrc/PipePair.cpp.i

CMakeFiles/SDL2_App.dir/ProjectSrc/PipePair.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SDL2_App.dir/ProjectSrc/PipePair.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/barnold/Code/C++/CPP-Coursework/Project-CW1/ProjectSrc/PipePair.cpp -o CMakeFiles/SDL2_App.dir/ProjectSrc/PipePair.cpp.s

# Object files for target SDL2_App
SDL2_App_OBJECTS = \
"CMakeFiles/SDL2_App.dir/src/mainfunction.cpp.o" \
"CMakeFiles/SDL2_App.dir/src/BaseEngine.cpp.o" \
"CMakeFiles/SDL2_App.dir/src/DisplayableObject.cpp.o" \
"CMakeFiles/SDL2_App.dir/src/DrawingSurface.cpp.o" \
"CMakeFiles/SDL2_App.dir/src/FontManager.cpp.o" \
"CMakeFiles/SDL2_App.dir/src/SimpleImage.cpp.o" \
"CMakeFiles/SDL2_App.dir/src/TileManager.cpp.o" \
"CMakeFiles/SDL2_App.dir/ProjectSrc/cw1_main.cpp.o" \
"CMakeFiles/SDL2_App.dir/ProjectSrc/Bird.cpp.o" \
"CMakeFiles/SDL2_App.dir/ProjectSrc/TileMap.cpp.o" \
"CMakeFiles/SDL2_App.dir/ProjectSrc/Pipe.cpp.o" \
"CMakeFiles/SDL2_App.dir/ProjectSrc/PipePair.cpp.o"

# External object files for target SDL2_App
SDL2_App_EXTERNAL_OBJECTS =

SDL2_App: CMakeFiles/SDL2_App.dir/src/mainfunction.cpp.o
SDL2_App: CMakeFiles/SDL2_App.dir/src/BaseEngine.cpp.o
SDL2_App: CMakeFiles/SDL2_App.dir/src/DisplayableObject.cpp.o
SDL2_App: CMakeFiles/SDL2_App.dir/src/DrawingSurface.cpp.o
SDL2_App: CMakeFiles/SDL2_App.dir/src/FontManager.cpp.o
SDL2_App: CMakeFiles/SDL2_App.dir/src/SimpleImage.cpp.o
SDL2_App: CMakeFiles/SDL2_App.dir/src/TileManager.cpp.o
SDL2_App: CMakeFiles/SDL2_App.dir/ProjectSrc/cw1_main.cpp.o
SDL2_App: CMakeFiles/SDL2_App.dir/ProjectSrc/Bird.cpp.o
SDL2_App: CMakeFiles/SDL2_App.dir/ProjectSrc/TileMap.cpp.o
SDL2_App: CMakeFiles/SDL2_App.dir/ProjectSrc/Pipe.cpp.o
SDL2_App: CMakeFiles/SDL2_App.dir/ProjectSrc/PipePair.cpp.o
SDL2_App: CMakeFiles/SDL2_App.dir/build.make
SDL2_App: /usr/lib/libSDL2main.a
SDL2_App: /usr/lib/libSDL2.so
SDL2_App: /usr/lib/libSDL2_ttf.so
SDL2_App: /usr/lib/libSDL2_image.so
SDL2_App: CMakeFiles/SDL2_App.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/barnold/Code/C++/CPP-Coursework/Project-CW1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable SDL2_App"
	/usr/bin/cmake -E copy_directory /home/barnold/Code/C++/CPP-Coursework/Project-CW1/src/resources /home/barnold/Code/C++/CPP-Coursework/Project-CW1/build
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SDL2_App.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SDL2_App.dir/build: SDL2_App
.PHONY : CMakeFiles/SDL2_App.dir/build

CMakeFiles/SDL2_App.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SDL2_App.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SDL2_App.dir/clean

CMakeFiles/SDL2_App.dir/depend:
	cd /home/barnold/Code/C++/CPP-Coursework/Project-CW1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/barnold/Code/C++/CPP-Coursework/Project-CW1 /home/barnold/Code/C++/CPP-Coursework/Project-CW1 /home/barnold/Code/C++/CPP-Coursework/Project-CW1/build /home/barnold/Code/C++/CPP-Coursework/Project-CW1/build /home/barnold/Code/C++/CPP-Coursework/Project-CW1/build/CMakeFiles/SDL2_App.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SDL2_App.dir/depend

