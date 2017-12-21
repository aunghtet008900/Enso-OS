# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/nick/work/Enso/panther_launcher

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nick/work/Enso/panther_launcher/build

# Include any dependencies generated for this target.
include src/CMakeFiles/pantherplugin.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/pantherplugin.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/pantherplugin.dir/flags.make

src/Xfce4PantherPlugin.c: src/pantherplugin_valac.stamp


src/pantherplugin_valac.stamp: ../src/Xfce4PantherPlugin.vala
src/pantherplugin_valac.stamp: ../vapi/garcon-1.vapi
src/pantherplugin_valac.stamp: ../vapi/libxfce4panel-2.0.vapi
src/pantherplugin_valac.stamp: ../vapi/libxfconf-0.vapi
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/nick/work/Enso/panther_launcher/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating Xfce4PantherPlugin.c"
	cd /home/nick/work/Enso/panther_launcher/build/src && /usr/bin/valac -C -b /home/nick/work/Enso/panther_launcher/src -d /home/nick/work/Enso/panther_launcher/build/src --pkg=gtk+-3.0 --pkg=glib-2.0 /home/nick/work/Enso/panther_launcher/src/Xfce4PantherPlugin.vala /home/nick/work/Enso/panther_launcher/vapi/garcon-1.vapi /home/nick/work/Enso/panther_launcher/vapi/libxfce4panel-2.0.vapi /home/nick/work/Enso/panther_launcher/vapi/libxfconf-0.vapi
	cd /home/nick/work/Enso/panther_launcher/build/src && touch /home/nick/work/Enso/panther_launcher/build/src/pantherplugin_valac.stamp

src/CMakeFiles/pantherplugin.dir/Xfce4PantherPlugin.c.o: src/CMakeFiles/pantherplugin.dir/flags.make
src/CMakeFiles/pantherplugin.dir/Xfce4PantherPlugin.c.o: src/Xfce4PantherPlugin.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nick/work/Enso/panther_launcher/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/CMakeFiles/pantherplugin.dir/Xfce4PantherPlugin.c.o"
	cd /home/nick/work/Enso/panther_launcher/build/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/pantherplugin.dir/Xfce4PantherPlugin.c.o   -c /home/nick/work/Enso/panther_launcher/build/src/Xfce4PantherPlugin.c

src/CMakeFiles/pantherplugin.dir/Xfce4PantherPlugin.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pantherplugin.dir/Xfce4PantherPlugin.c.i"
	cd /home/nick/work/Enso/panther_launcher/build/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nick/work/Enso/panther_launcher/build/src/Xfce4PantherPlugin.c > CMakeFiles/pantherplugin.dir/Xfce4PantherPlugin.c.i

src/CMakeFiles/pantherplugin.dir/Xfce4PantherPlugin.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pantherplugin.dir/Xfce4PantherPlugin.c.s"
	cd /home/nick/work/Enso/panther_launcher/build/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nick/work/Enso/panther_launcher/build/src/Xfce4PantherPlugin.c -o CMakeFiles/pantherplugin.dir/Xfce4PantherPlugin.c.s

src/CMakeFiles/pantherplugin.dir/Xfce4PantherPlugin.c.o.requires:

.PHONY : src/CMakeFiles/pantherplugin.dir/Xfce4PantherPlugin.c.o.requires

src/CMakeFiles/pantherplugin.dir/Xfce4PantherPlugin.c.o.provides: src/CMakeFiles/pantherplugin.dir/Xfce4PantherPlugin.c.o.requires
	$(MAKE) -f src/CMakeFiles/pantherplugin.dir/build.make src/CMakeFiles/pantherplugin.dir/Xfce4PantherPlugin.c.o.provides.build
.PHONY : src/CMakeFiles/pantherplugin.dir/Xfce4PantherPlugin.c.o.provides

src/CMakeFiles/pantherplugin.dir/Xfce4PantherPlugin.c.o.provides.build: src/CMakeFiles/pantherplugin.dir/Xfce4PantherPlugin.c.o


# Object files for target pantherplugin
pantherplugin_OBJECTS = \
"CMakeFiles/pantherplugin.dir/Xfce4PantherPlugin.c.o"

# External object files for target pantherplugin
pantherplugin_EXTERNAL_OBJECTS =

src/libpantherplugin.so: src/CMakeFiles/pantherplugin.dir/Xfce4PantherPlugin.c.o
src/libpantherplugin.so: src/CMakeFiles/pantherplugin.dir/build.make
src/libpantherplugin.so: src/CMakeFiles/pantherplugin.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nick/work/Enso/panther_launcher/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C shared library libpantherplugin.so"
	cd /home/nick/work/Enso/panther_launcher/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pantherplugin.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/pantherplugin.dir/build: src/libpantherplugin.so

.PHONY : src/CMakeFiles/pantherplugin.dir/build

src/CMakeFiles/pantherplugin.dir/requires: src/CMakeFiles/pantherplugin.dir/Xfce4PantherPlugin.c.o.requires

.PHONY : src/CMakeFiles/pantherplugin.dir/requires

src/CMakeFiles/pantherplugin.dir/clean:
	cd /home/nick/work/Enso/panther_launcher/build/src && $(CMAKE_COMMAND) -P CMakeFiles/pantherplugin.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/pantherplugin.dir/clean

src/CMakeFiles/pantherplugin.dir/depend: src/Xfce4PantherPlugin.c
src/CMakeFiles/pantherplugin.dir/depend: src/pantherplugin_valac.stamp
	cd /home/nick/work/Enso/panther_launcher/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nick/work/Enso/panther_launcher /home/nick/work/Enso/panther_launcher/src /home/nick/work/Enso/panther_launcher/build /home/nick/work/Enso/panther_launcher/build/src /home/nick/work/Enso/panther_launcher/build/src/CMakeFiles/pantherplugin.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/pantherplugin.dir/depend

