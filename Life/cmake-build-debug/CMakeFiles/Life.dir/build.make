# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.21

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\GitHub\LifeGame\Life

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\GitHub\LifeGame\Life\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Life.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Life.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Life.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Life.dir/flags.make

CMakeFiles/Life.dir/main.cpp.obj: CMakeFiles/Life.dir/flags.make
CMakeFiles/Life.dir/main.cpp.obj: CMakeFiles/Life.dir/includes_CXX.rsp
CMakeFiles/Life.dir/main.cpp.obj: ../main.cpp
CMakeFiles/Life.dir/main.cpp.obj: CMakeFiles/Life.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\GitHub\LifeGame\Life\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Life.dir/main.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Life.dir/main.cpp.obj -MF CMakeFiles\Life.dir\main.cpp.obj.d -o CMakeFiles\Life.dir\main.cpp.obj -c C:\GitHub\LifeGame\Life\main.cpp

CMakeFiles/Life.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Life.dir/main.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\GitHub\LifeGame\Life\main.cpp > CMakeFiles\Life.dir\main.cpp.i

CMakeFiles/Life.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Life.dir/main.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\GitHub\LifeGame\Life\main.cpp -o CMakeFiles\Life.dir\main.cpp.s

CMakeFiles/Life.dir/Classes/Field.cpp.obj: CMakeFiles/Life.dir/flags.make
CMakeFiles/Life.dir/Classes/Field.cpp.obj: CMakeFiles/Life.dir/includes_CXX.rsp
CMakeFiles/Life.dir/Classes/Field.cpp.obj: ../Classes/Field.cpp
CMakeFiles/Life.dir/Classes/Field.cpp.obj: CMakeFiles/Life.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\GitHub\LifeGame\Life\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Life.dir/Classes/Field.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Life.dir/Classes/Field.cpp.obj -MF CMakeFiles\Life.dir\Classes\Field.cpp.obj.d -o CMakeFiles\Life.dir\Classes\Field.cpp.obj -c C:\GitHub\LifeGame\Life\Classes\Field.cpp

CMakeFiles/Life.dir/Classes/Field.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Life.dir/Classes/Field.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\GitHub\LifeGame\Life\Classes\Field.cpp > CMakeFiles\Life.dir\Classes\Field.cpp.i

CMakeFiles/Life.dir/Classes/Field.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Life.dir/Classes/Field.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\GitHub\LifeGame\Life\Classes\Field.cpp -o CMakeFiles\Life.dir\Classes\Field.cpp.s

CMakeFiles/Life.dir/Classes/Game.cpp.obj: CMakeFiles/Life.dir/flags.make
CMakeFiles/Life.dir/Classes/Game.cpp.obj: CMakeFiles/Life.dir/includes_CXX.rsp
CMakeFiles/Life.dir/Classes/Game.cpp.obj: ../Classes/Game.cpp
CMakeFiles/Life.dir/Classes/Game.cpp.obj: CMakeFiles/Life.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\GitHub\LifeGame\Life\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Life.dir/Classes/Game.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Life.dir/Classes/Game.cpp.obj -MF CMakeFiles\Life.dir\Classes\Game.cpp.obj.d -o CMakeFiles\Life.dir\Classes\Game.cpp.obj -c C:\GitHub\LifeGame\Life\Classes\Game.cpp

CMakeFiles/Life.dir/Classes/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Life.dir/Classes/Game.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\GitHub\LifeGame\Life\Classes\Game.cpp > CMakeFiles\Life.dir\Classes\Game.cpp.i

CMakeFiles/Life.dir/Classes/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Life.dir/Classes/Game.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\GitHub\LifeGame\Life\Classes\Game.cpp -o CMakeFiles\Life.dir\Classes\Game.cpp.s

CMakeFiles/Life.dir/Classes/Button.cpp.obj: CMakeFiles/Life.dir/flags.make
CMakeFiles/Life.dir/Classes/Button.cpp.obj: CMakeFiles/Life.dir/includes_CXX.rsp
CMakeFiles/Life.dir/Classes/Button.cpp.obj: ../Classes/Button.cpp
CMakeFiles/Life.dir/Classes/Button.cpp.obj: CMakeFiles/Life.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\GitHub\LifeGame\Life\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Life.dir/Classes/Button.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Life.dir/Classes/Button.cpp.obj -MF CMakeFiles\Life.dir\Classes\Button.cpp.obj.d -o CMakeFiles\Life.dir\Classes\Button.cpp.obj -c C:\GitHub\LifeGame\Life\Classes\Button.cpp

CMakeFiles/Life.dir/Classes/Button.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Life.dir/Classes/Button.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\GitHub\LifeGame\Life\Classes\Button.cpp > CMakeFiles\Life.dir\Classes\Button.cpp.i

CMakeFiles/Life.dir/Classes/Button.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Life.dir/Classes/Button.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\GitHub\LifeGame\Life\Classes\Button.cpp -o CMakeFiles\Life.dir\Classes\Button.cpp.s

CMakeFiles/Life.dir/Classes/Menu.cpp.obj: CMakeFiles/Life.dir/flags.make
CMakeFiles/Life.dir/Classes/Menu.cpp.obj: CMakeFiles/Life.dir/includes_CXX.rsp
CMakeFiles/Life.dir/Classes/Menu.cpp.obj: ../Classes/Menu.cpp
CMakeFiles/Life.dir/Classes/Menu.cpp.obj: CMakeFiles/Life.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\GitHub\LifeGame\Life\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Life.dir/Classes/Menu.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Life.dir/Classes/Menu.cpp.obj -MF CMakeFiles\Life.dir\Classes\Menu.cpp.obj.d -o CMakeFiles\Life.dir\Classes\Menu.cpp.obj -c C:\GitHub\LifeGame\Life\Classes\Menu.cpp

CMakeFiles/Life.dir/Classes/Menu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Life.dir/Classes/Menu.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\GitHub\LifeGame\Life\Classes\Menu.cpp > CMakeFiles\Life.dir\Classes\Menu.cpp.i

CMakeFiles/Life.dir/Classes/Menu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Life.dir/Classes/Menu.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\GitHub\LifeGame\Life\Classes\Menu.cpp -o CMakeFiles\Life.dir\Classes\Menu.cpp.s

CMakeFiles/Life.dir/Classes/Inventory.cpp.obj: CMakeFiles/Life.dir/flags.make
CMakeFiles/Life.dir/Classes/Inventory.cpp.obj: CMakeFiles/Life.dir/includes_CXX.rsp
CMakeFiles/Life.dir/Classes/Inventory.cpp.obj: ../Classes/Inventory.cpp
CMakeFiles/Life.dir/Classes/Inventory.cpp.obj: CMakeFiles/Life.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\GitHub\LifeGame\Life\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Life.dir/Classes/Inventory.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Life.dir/Classes/Inventory.cpp.obj -MF CMakeFiles\Life.dir\Classes\Inventory.cpp.obj.d -o CMakeFiles\Life.dir\Classes\Inventory.cpp.obj -c C:\GitHub\LifeGame\Life\Classes\Inventory.cpp

CMakeFiles/Life.dir/Classes/Inventory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Life.dir/Classes/Inventory.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\GitHub\LifeGame\Life\Classes\Inventory.cpp > CMakeFiles\Life.dir\Classes\Inventory.cpp.i

CMakeFiles/Life.dir/Classes/Inventory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Life.dir/Classes/Inventory.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\GitHub\LifeGame\Life\Classes\Inventory.cpp -o CMakeFiles\Life.dir\Classes\Inventory.cpp.s

# Object files for target Life
Life_OBJECTS = \
"CMakeFiles/Life.dir/main.cpp.obj" \
"CMakeFiles/Life.dir/Classes/Field.cpp.obj" \
"CMakeFiles/Life.dir/Classes/Game.cpp.obj" \
"CMakeFiles/Life.dir/Classes/Button.cpp.obj" \
"CMakeFiles/Life.dir/Classes/Menu.cpp.obj" \
"CMakeFiles/Life.dir/Classes/Inventory.cpp.obj"

# External object files for target Life
Life_EXTERNAL_OBJECTS =

Life.exe: CMakeFiles/Life.dir/main.cpp.obj
Life.exe: CMakeFiles/Life.dir/Classes/Field.cpp.obj
Life.exe: CMakeFiles/Life.dir/Classes/Game.cpp.obj
Life.exe: CMakeFiles/Life.dir/Classes/Button.cpp.obj
Life.exe: CMakeFiles/Life.dir/Classes/Menu.cpp.obj
Life.exe: CMakeFiles/Life.dir/Classes/Inventory.cpp.obj
Life.exe: CMakeFiles/Life.dir/build.make
Life.exe: C:/SFML-2.5.1/lib/libsfml-system-d.a
Life.exe: C:/SFML-2.5.1/lib/libsfml-window-d.a
Life.exe: C:/SFML-2.5.1/lib/libsfml-graphics-d.a
Life.exe: C:/SFML-2.5.1/lib/libsfml-network-d.a
Life.exe: C:/SFML-2.5.1/lib/libsfml-audio-d.a
Life.exe: CMakeFiles/Life.dir/linklibs.rsp
Life.exe: CMakeFiles/Life.dir/objects1.rsp
Life.exe: CMakeFiles/Life.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\GitHub\LifeGame\Life\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable Life.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Life.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Life.dir/build: Life.exe
.PHONY : CMakeFiles/Life.dir/build

CMakeFiles/Life.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Life.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Life.dir/clean

CMakeFiles/Life.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\GitHub\LifeGame\Life C:\GitHub\LifeGame\Life C:\GitHub\LifeGame\Life\cmake-build-debug C:\GitHub\LifeGame\Life\cmake-build-debug C:\GitHub\LifeGame\Life\cmake-build-debug\CMakeFiles\Life.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Life.dir/depend

