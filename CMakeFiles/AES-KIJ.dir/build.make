# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.22.2/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.22.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/gayuhkautaman/Documents/code/cpp/AES-KIJ

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/gayuhkautaman/Documents/code/cpp/AES-KIJ

# Include any dependencies generated for this target.
include CMakeFiles/AES-KIJ.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/AES-KIJ.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/AES-KIJ.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AES-KIJ.dir/flags.make

CMakeFiles/AES-KIJ.dir/AES-KIJ_autogen/mocs_compilation.cpp.o: CMakeFiles/AES-KIJ.dir/flags.make
CMakeFiles/AES-KIJ.dir/AES-KIJ_autogen/mocs_compilation.cpp.o: AES-KIJ_autogen/mocs_compilation.cpp
CMakeFiles/AES-KIJ.dir/AES-KIJ_autogen/mocs_compilation.cpp.o: CMakeFiles/AES-KIJ.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gayuhkautaman/Documents/code/cpp/AES-KIJ/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/AES-KIJ.dir/AES-KIJ_autogen/mocs_compilation.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AES-KIJ.dir/AES-KIJ_autogen/mocs_compilation.cpp.o -MF CMakeFiles/AES-KIJ.dir/AES-KIJ_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/AES-KIJ.dir/AES-KIJ_autogen/mocs_compilation.cpp.o -c /Users/gayuhkautaman/Documents/code/cpp/AES-KIJ/AES-KIJ_autogen/mocs_compilation.cpp

CMakeFiles/AES-KIJ.dir/AES-KIJ_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AES-KIJ.dir/AES-KIJ_autogen/mocs_compilation.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/gayuhkautaman/Documents/code/cpp/AES-KIJ/AES-KIJ_autogen/mocs_compilation.cpp > CMakeFiles/AES-KIJ.dir/AES-KIJ_autogen/mocs_compilation.cpp.i

CMakeFiles/AES-KIJ.dir/AES-KIJ_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AES-KIJ.dir/AES-KIJ_autogen/mocs_compilation.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/gayuhkautaman/Documents/code/cpp/AES-KIJ/AES-KIJ_autogen/mocs_compilation.cpp -o CMakeFiles/AES-KIJ.dir/AES-KIJ_autogen/mocs_compilation.cpp.s

CMakeFiles/AES-KIJ.dir/main.cpp.o: CMakeFiles/AES-KIJ.dir/flags.make
CMakeFiles/AES-KIJ.dir/main.cpp.o: main.cpp
CMakeFiles/AES-KIJ.dir/main.cpp.o: CMakeFiles/AES-KIJ.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gayuhkautaman/Documents/code/cpp/AES-KIJ/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/AES-KIJ.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AES-KIJ.dir/main.cpp.o -MF CMakeFiles/AES-KIJ.dir/main.cpp.o.d -o CMakeFiles/AES-KIJ.dir/main.cpp.o -c /Users/gayuhkautaman/Documents/code/cpp/AES-KIJ/main.cpp

CMakeFiles/AES-KIJ.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AES-KIJ.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/gayuhkautaman/Documents/code/cpp/AES-KIJ/main.cpp > CMakeFiles/AES-KIJ.dir/main.cpp.i

CMakeFiles/AES-KIJ.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AES-KIJ.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/gayuhkautaman/Documents/code/cpp/AES-KIJ/main.cpp -o CMakeFiles/AES-KIJ.dir/main.cpp.s

CMakeFiles/AES-KIJ.dir/mainwindow.cpp.o: CMakeFiles/AES-KIJ.dir/flags.make
CMakeFiles/AES-KIJ.dir/mainwindow.cpp.o: mainwindow.cpp
CMakeFiles/AES-KIJ.dir/mainwindow.cpp.o: CMakeFiles/AES-KIJ.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gayuhkautaman/Documents/code/cpp/AES-KIJ/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/AES-KIJ.dir/mainwindow.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AES-KIJ.dir/mainwindow.cpp.o -MF CMakeFiles/AES-KIJ.dir/mainwindow.cpp.o.d -o CMakeFiles/AES-KIJ.dir/mainwindow.cpp.o -c /Users/gayuhkautaman/Documents/code/cpp/AES-KIJ/mainwindow.cpp

CMakeFiles/AES-KIJ.dir/mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AES-KIJ.dir/mainwindow.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/gayuhkautaman/Documents/code/cpp/AES-KIJ/mainwindow.cpp > CMakeFiles/AES-KIJ.dir/mainwindow.cpp.i

CMakeFiles/AES-KIJ.dir/mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AES-KIJ.dir/mainwindow.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/gayuhkautaman/Documents/code/cpp/AES-KIJ/mainwindow.cpp -o CMakeFiles/AES-KIJ.dir/mainwindow.cpp.s

CMakeFiles/AES-KIJ.dir/nativeaes.cpp.o: CMakeFiles/AES-KIJ.dir/flags.make
CMakeFiles/AES-KIJ.dir/nativeaes.cpp.o: nativeaes.cpp
CMakeFiles/AES-KIJ.dir/nativeaes.cpp.o: CMakeFiles/AES-KIJ.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gayuhkautaman/Documents/code/cpp/AES-KIJ/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/AES-KIJ.dir/nativeaes.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AES-KIJ.dir/nativeaes.cpp.o -MF CMakeFiles/AES-KIJ.dir/nativeaes.cpp.o.d -o CMakeFiles/AES-KIJ.dir/nativeaes.cpp.o -c /Users/gayuhkautaman/Documents/code/cpp/AES-KIJ/nativeaes.cpp

CMakeFiles/AES-KIJ.dir/nativeaes.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AES-KIJ.dir/nativeaes.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/gayuhkautaman/Documents/code/cpp/AES-KIJ/nativeaes.cpp > CMakeFiles/AES-KIJ.dir/nativeaes.cpp.i

CMakeFiles/AES-KIJ.dir/nativeaes.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AES-KIJ.dir/nativeaes.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/gayuhkautaman/Documents/code/cpp/AES-KIJ/nativeaes.cpp -o CMakeFiles/AES-KIJ.dir/nativeaes.cpp.s

CMakeFiles/AES-KIJ.dir/libaes.cpp.o: CMakeFiles/AES-KIJ.dir/flags.make
CMakeFiles/AES-KIJ.dir/libaes.cpp.o: libaes.cpp
CMakeFiles/AES-KIJ.dir/libaes.cpp.o: CMakeFiles/AES-KIJ.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gayuhkautaman/Documents/code/cpp/AES-KIJ/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/AES-KIJ.dir/libaes.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AES-KIJ.dir/libaes.cpp.o -MF CMakeFiles/AES-KIJ.dir/libaes.cpp.o.d -o CMakeFiles/AES-KIJ.dir/libaes.cpp.o -c /Users/gayuhkautaman/Documents/code/cpp/AES-KIJ/libaes.cpp

CMakeFiles/AES-KIJ.dir/libaes.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AES-KIJ.dir/libaes.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/gayuhkautaman/Documents/code/cpp/AES-KIJ/libaes.cpp > CMakeFiles/AES-KIJ.dir/libaes.cpp.i

CMakeFiles/AES-KIJ.dir/libaes.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AES-KIJ.dir/libaes.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/gayuhkautaman/Documents/code/cpp/AES-KIJ/libaes.cpp -o CMakeFiles/AES-KIJ.dir/libaes.cpp.s

CMakeFiles/AES-KIJ.dir/server.cpp.o: CMakeFiles/AES-KIJ.dir/flags.make
CMakeFiles/AES-KIJ.dir/server.cpp.o: server.cpp
CMakeFiles/AES-KIJ.dir/server.cpp.o: CMakeFiles/AES-KIJ.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gayuhkautaman/Documents/code/cpp/AES-KIJ/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/AES-KIJ.dir/server.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AES-KIJ.dir/server.cpp.o -MF CMakeFiles/AES-KIJ.dir/server.cpp.o.d -o CMakeFiles/AES-KIJ.dir/server.cpp.o -c /Users/gayuhkautaman/Documents/code/cpp/AES-KIJ/server.cpp

CMakeFiles/AES-KIJ.dir/server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AES-KIJ.dir/server.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/gayuhkautaman/Documents/code/cpp/AES-KIJ/server.cpp > CMakeFiles/AES-KIJ.dir/server.cpp.i

CMakeFiles/AES-KIJ.dir/server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AES-KIJ.dir/server.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/gayuhkautaman/Documents/code/cpp/AES-KIJ/server.cpp -o CMakeFiles/AES-KIJ.dir/server.cpp.s

# Object files for target AES-KIJ
AES__KIJ_OBJECTS = \
"CMakeFiles/AES-KIJ.dir/AES-KIJ_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/AES-KIJ.dir/main.cpp.o" \
"CMakeFiles/AES-KIJ.dir/mainwindow.cpp.o" \
"CMakeFiles/AES-KIJ.dir/nativeaes.cpp.o" \
"CMakeFiles/AES-KIJ.dir/libaes.cpp.o" \
"CMakeFiles/AES-KIJ.dir/server.cpp.o"

# External object files for target AES-KIJ
AES__KIJ_EXTERNAL_OBJECTS =

AES-KIJ.app/Contents/MacOS/AES-KIJ: CMakeFiles/AES-KIJ.dir/AES-KIJ_autogen/mocs_compilation.cpp.o
AES-KIJ.app/Contents/MacOS/AES-KIJ: CMakeFiles/AES-KIJ.dir/main.cpp.o
AES-KIJ.app/Contents/MacOS/AES-KIJ: CMakeFiles/AES-KIJ.dir/mainwindow.cpp.o
AES-KIJ.app/Contents/MacOS/AES-KIJ: CMakeFiles/AES-KIJ.dir/nativeaes.cpp.o
AES-KIJ.app/Contents/MacOS/AES-KIJ: CMakeFiles/AES-KIJ.dir/libaes.cpp.o
AES-KIJ.app/Contents/MacOS/AES-KIJ: CMakeFiles/AES-KIJ.dir/server.cpp.o
AES-KIJ.app/Contents/MacOS/AES-KIJ: CMakeFiles/AES-KIJ.dir/build.make
AES-KIJ.app/Contents/MacOS/AES-KIJ: /opt/homebrew/opt/qt@5/lib/QtWidgets.framework/QtWidgets
AES-KIJ.app/Contents/MacOS/AES-KIJ: /opt/homebrew/opt/qt@5/lib/QtQuick.framework/QtQuick
AES-KIJ.app/Contents/MacOS/AES-KIJ: /opt/homebrew/opt/qt@5/lib/QtGui.framework/QtGui
AES-KIJ.app/Contents/MacOS/AES-KIJ: /opt/homebrew/opt/qt@5/lib/QtQmlModels.framework/QtQmlModels
AES-KIJ.app/Contents/MacOS/AES-KIJ: /opt/homebrew/opt/qt@5/lib/QtQml.framework/QtQml
AES-KIJ.app/Contents/MacOS/AES-KIJ: /opt/homebrew/opt/qt@5/lib/QtNetwork.framework/QtNetwork
AES-KIJ.app/Contents/MacOS/AES-KIJ: /opt/homebrew/opt/qt@5/lib/QtCore.framework/QtCore
AES-KIJ.app/Contents/MacOS/AES-KIJ: CMakeFiles/AES-KIJ.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/gayuhkautaman/Documents/code/cpp/AES-KIJ/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable AES-KIJ.app/Contents/MacOS/AES-KIJ"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AES-KIJ.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AES-KIJ.dir/build: AES-KIJ.app/Contents/MacOS/AES-KIJ
.PHONY : CMakeFiles/AES-KIJ.dir/build

CMakeFiles/AES-KIJ.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/AES-KIJ.dir/cmake_clean.cmake
.PHONY : CMakeFiles/AES-KIJ.dir/clean

CMakeFiles/AES-KIJ.dir/depend:
	cd /Users/gayuhkautaman/Documents/code/cpp/AES-KIJ && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/gayuhkautaman/Documents/code/cpp/AES-KIJ /Users/gayuhkautaman/Documents/code/cpp/AES-KIJ /Users/gayuhkautaman/Documents/code/cpp/AES-KIJ /Users/gayuhkautaman/Documents/code/cpp/AES-KIJ /Users/gayuhkautaman/Documents/code/cpp/AES-KIJ/CMakeFiles/AES-KIJ.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/AES-KIJ.dir/depend

