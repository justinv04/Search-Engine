# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/jvincent/Desktop/Projects/Coding_Projects/C++_Projects/Search_Engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jvincent/Desktop/Projects/Coding_Projects/C++_Projects/Search_Engine/build

# Include any dependencies generated for this target.
include CMakeFiles/supersearch.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/supersearch.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/supersearch.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/supersearch.dir/flags.make

CMakeFiles/supersearch.dir/main.cpp.o: CMakeFiles/supersearch.dir/flags.make
CMakeFiles/supersearch.dir/main.cpp.o: /Users/jvincent/Desktop/Projects/Coding_Projects/C++_Projects/Search_Engine/main.cpp
CMakeFiles/supersearch.dir/main.cpp.o: CMakeFiles/supersearch.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/jvincent/Desktop/Projects/Coding_Projects/C++_Projects/Search_Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/supersearch.dir/main.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/supersearch.dir/main.cpp.o -MF CMakeFiles/supersearch.dir/main.cpp.o.d -o CMakeFiles/supersearch.dir/main.cpp.o -c /Users/jvincent/Desktop/Projects/Coding_Projects/C++_Projects/Search_Engine/main.cpp

CMakeFiles/supersearch.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/supersearch.dir/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jvincent/Desktop/Projects/Coding_Projects/C++_Projects/Search_Engine/main.cpp > CMakeFiles/supersearch.dir/main.cpp.i

CMakeFiles/supersearch.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/supersearch.dir/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jvincent/Desktop/Projects/Coding_Projects/C++_Projects/Search_Engine/main.cpp -o CMakeFiles/supersearch.dir/main.cpp.s

CMakeFiles/supersearch.dir/AVLTree.cpp.o: CMakeFiles/supersearch.dir/flags.make
CMakeFiles/supersearch.dir/AVLTree.cpp.o: /Users/jvincent/Desktop/Projects/Coding_Projects/C++_Projects/Search_Engine/AVLTree.cpp
CMakeFiles/supersearch.dir/AVLTree.cpp.o: CMakeFiles/supersearch.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/jvincent/Desktop/Projects/Coding_Projects/C++_Projects/Search_Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/supersearch.dir/AVLTree.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/supersearch.dir/AVLTree.cpp.o -MF CMakeFiles/supersearch.dir/AVLTree.cpp.o.d -o CMakeFiles/supersearch.dir/AVLTree.cpp.o -c /Users/jvincent/Desktop/Projects/Coding_Projects/C++_Projects/Search_Engine/AVLTree.cpp

CMakeFiles/supersearch.dir/AVLTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/supersearch.dir/AVLTree.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jvincent/Desktop/Projects/Coding_Projects/C++_Projects/Search_Engine/AVLTree.cpp > CMakeFiles/supersearch.dir/AVLTree.cpp.i

CMakeFiles/supersearch.dir/AVLTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/supersearch.dir/AVLTree.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jvincent/Desktop/Projects/Coding_Projects/C++_Projects/Search_Engine/AVLTree.cpp -o CMakeFiles/supersearch.dir/AVLTree.cpp.s

CMakeFiles/supersearch.dir/DocumentParser.cpp.o: CMakeFiles/supersearch.dir/flags.make
CMakeFiles/supersearch.dir/DocumentParser.cpp.o: /Users/jvincent/Desktop/Projects/Coding_Projects/C++_Projects/Search_Engine/DocumentParser.cpp
CMakeFiles/supersearch.dir/DocumentParser.cpp.o: CMakeFiles/supersearch.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/jvincent/Desktop/Projects/Coding_Projects/C++_Projects/Search_Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/supersearch.dir/DocumentParser.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/supersearch.dir/DocumentParser.cpp.o -MF CMakeFiles/supersearch.dir/DocumentParser.cpp.o.d -o CMakeFiles/supersearch.dir/DocumentParser.cpp.o -c /Users/jvincent/Desktop/Projects/Coding_Projects/C++_Projects/Search_Engine/DocumentParser.cpp

CMakeFiles/supersearch.dir/DocumentParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/supersearch.dir/DocumentParser.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jvincent/Desktop/Projects/Coding_Projects/C++_Projects/Search_Engine/DocumentParser.cpp > CMakeFiles/supersearch.dir/DocumentParser.cpp.i

CMakeFiles/supersearch.dir/DocumentParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/supersearch.dir/DocumentParser.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jvincent/Desktop/Projects/Coding_Projects/C++_Projects/Search_Engine/DocumentParser.cpp -o CMakeFiles/supersearch.dir/DocumentParser.cpp.s

CMakeFiles/supersearch.dir/IndexHandler.cpp.o: CMakeFiles/supersearch.dir/flags.make
CMakeFiles/supersearch.dir/IndexHandler.cpp.o: /Users/jvincent/Desktop/Projects/Coding_Projects/C++_Projects/Search_Engine/IndexHandler.cpp
CMakeFiles/supersearch.dir/IndexHandler.cpp.o: CMakeFiles/supersearch.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/jvincent/Desktop/Projects/Coding_Projects/C++_Projects/Search_Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/supersearch.dir/IndexHandler.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/supersearch.dir/IndexHandler.cpp.o -MF CMakeFiles/supersearch.dir/IndexHandler.cpp.o.d -o CMakeFiles/supersearch.dir/IndexHandler.cpp.o -c /Users/jvincent/Desktop/Projects/Coding_Projects/C++_Projects/Search_Engine/IndexHandler.cpp

CMakeFiles/supersearch.dir/IndexHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/supersearch.dir/IndexHandler.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jvincent/Desktop/Projects/Coding_Projects/C++_Projects/Search_Engine/IndexHandler.cpp > CMakeFiles/supersearch.dir/IndexHandler.cpp.i

CMakeFiles/supersearch.dir/IndexHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/supersearch.dir/IndexHandler.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jvincent/Desktop/Projects/Coding_Projects/C++_Projects/Search_Engine/IndexHandler.cpp -o CMakeFiles/supersearch.dir/IndexHandler.cpp.s

CMakeFiles/supersearch.dir/QueryProcessor.cpp.o: CMakeFiles/supersearch.dir/flags.make
CMakeFiles/supersearch.dir/QueryProcessor.cpp.o: /Users/jvincent/Desktop/Projects/Coding_Projects/C++_Projects/Search_Engine/QueryProcessor.cpp
CMakeFiles/supersearch.dir/QueryProcessor.cpp.o: CMakeFiles/supersearch.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/jvincent/Desktop/Projects/Coding_Projects/C++_Projects/Search_Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/supersearch.dir/QueryProcessor.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/supersearch.dir/QueryProcessor.cpp.o -MF CMakeFiles/supersearch.dir/QueryProcessor.cpp.o.d -o CMakeFiles/supersearch.dir/QueryProcessor.cpp.o -c /Users/jvincent/Desktop/Projects/Coding_Projects/C++_Projects/Search_Engine/QueryProcessor.cpp

CMakeFiles/supersearch.dir/QueryProcessor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/supersearch.dir/QueryProcessor.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jvincent/Desktop/Projects/Coding_Projects/C++_Projects/Search_Engine/QueryProcessor.cpp > CMakeFiles/supersearch.dir/QueryProcessor.cpp.i

CMakeFiles/supersearch.dir/QueryProcessor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/supersearch.dir/QueryProcessor.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jvincent/Desktop/Projects/Coding_Projects/C++_Projects/Search_Engine/QueryProcessor.cpp -o CMakeFiles/supersearch.dir/QueryProcessor.cpp.s

CMakeFiles/supersearch.dir/porter2_stemmer.cpp.o: CMakeFiles/supersearch.dir/flags.make
CMakeFiles/supersearch.dir/porter2_stemmer.cpp.o: /Users/jvincent/Desktop/Projects/Coding_Projects/C++_Projects/Search_Engine/porter2_stemmer.cpp
CMakeFiles/supersearch.dir/porter2_stemmer.cpp.o: CMakeFiles/supersearch.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/jvincent/Desktop/Projects/Coding_Projects/C++_Projects/Search_Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/supersearch.dir/porter2_stemmer.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/supersearch.dir/porter2_stemmer.cpp.o -MF CMakeFiles/supersearch.dir/porter2_stemmer.cpp.o.d -o CMakeFiles/supersearch.dir/porter2_stemmer.cpp.o -c /Users/jvincent/Desktop/Projects/Coding_Projects/C++_Projects/Search_Engine/porter2_stemmer.cpp

CMakeFiles/supersearch.dir/porter2_stemmer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/supersearch.dir/porter2_stemmer.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jvincent/Desktop/Projects/Coding_Projects/C++_Projects/Search_Engine/porter2_stemmer.cpp > CMakeFiles/supersearch.dir/porter2_stemmer.cpp.i

CMakeFiles/supersearch.dir/porter2_stemmer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/supersearch.dir/porter2_stemmer.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jvincent/Desktop/Projects/Coding_Projects/C++_Projects/Search_Engine/porter2_stemmer.cpp -o CMakeFiles/supersearch.dir/porter2_stemmer.cpp.s

# Object files for target supersearch
supersearch_OBJECTS = \
"CMakeFiles/supersearch.dir/main.cpp.o" \
"CMakeFiles/supersearch.dir/AVLTree.cpp.o" \
"CMakeFiles/supersearch.dir/DocumentParser.cpp.o" \
"CMakeFiles/supersearch.dir/IndexHandler.cpp.o" \
"CMakeFiles/supersearch.dir/QueryProcessor.cpp.o" \
"CMakeFiles/supersearch.dir/porter2_stemmer.cpp.o"

# External object files for target supersearch
supersearch_EXTERNAL_OBJECTS =

supersearch: CMakeFiles/supersearch.dir/main.cpp.o
supersearch: CMakeFiles/supersearch.dir/AVLTree.cpp.o
supersearch: CMakeFiles/supersearch.dir/DocumentParser.cpp.o
supersearch: CMakeFiles/supersearch.dir/IndexHandler.cpp.o
supersearch: CMakeFiles/supersearch.dir/QueryProcessor.cpp.o
supersearch: CMakeFiles/supersearch.dir/porter2_stemmer.cpp.o
supersearch: CMakeFiles/supersearch.dir/build.make
supersearch: CMakeFiles/supersearch.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/jvincent/Desktop/Projects/Coding_Projects/C++_Projects/Search_Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable supersearch"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/supersearch.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/supersearch.dir/build: supersearch
.PHONY : CMakeFiles/supersearch.dir/build

CMakeFiles/supersearch.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/supersearch.dir/cmake_clean.cmake
.PHONY : CMakeFiles/supersearch.dir/clean

CMakeFiles/supersearch.dir/depend:
	cd /Users/jvincent/Desktop/Projects/Coding_Projects/C++_Projects/Search_Engine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jvincent/Desktop/Projects/Coding_Projects/C++_Projects/Search_Engine /Users/jvincent/Desktop/Projects/Coding_Projects/C++_Projects/Search_Engine /Users/jvincent/Desktop/Projects/Coding_Projects/C++_Projects/Search_Engine/build /Users/jvincent/Desktop/Projects/Coding_Projects/C++_Projects/Search_Engine/build /Users/jvincent/Desktop/Projects/Coding_Projects/C++_Projects/Search_Engine/build/CMakeFiles/supersearch.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/supersearch.dir/depend

