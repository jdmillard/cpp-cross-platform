## UUID Library Testing

A basic linking of UUID libraries and implementation with CMake.

### Some Specifics

A working example with comments is provided.

### Run Commands
TODO: update for cross platform support
```bash
cd build/
cmake ..
make
./uuid-run
```

### Resource Links
* [Link](https://stackoverflow.com/)

### Temporary notes while debugging running with Windows
```
to run without any visual studio dependencies,
install cmake and allow the installation to add cmake to path (https://cmake.org/download/)
install mingw (minimalist gnu for windows, has GCC for windows) http://www.mingw.org/
after the mingw installer is set up, a window will let you select components to install
select:
ming32-base (A Basic MinGW Installation) (contains mingw32-make)
ming32-gcc-g++ (The GNU C++ Compiler)
ming32-gccobjc (The GNU Objective-C Compiler)
apply changes
add mingw to path This PC > Properties > Advanced System Settings > Advanced > Environment Variables > Edit System Path > Add "C:\MinGW\bin"
test by opening cmd and typing g++ --version
to generate make files go to /path/to/repo/build/ and run (not with git bash due to conflicts):
cmake.exe .. -G "MinGW Makefiles"
to compile run
mingw32-make.exe
to execute run
uuid-run.exe

to run with visual studio:

TODO
native import to VS (will VS change cmakelists.txt? will this cause chaos?)
use cmake to generate sln and project files?

other notes:
cmake.exe .. -G "MinGW Makefiles"
cmake.exe .. -G "NMake Makefiles"
TODO: make cleanup script for windows
```

### Old README.md
TODO: parse for what to keep
```
## Repository Name

Description of this software

### Build, Compile, and Run

Overview about what is supported

##### Linux

Notes about Linux (`Ubuntu 16.04`)

'''bash
cd build/
cmake ..
make
./orb-tracker
'''

##### Windows

Notes about Windows (`Windows 10 Version 1709`)

##### macOS

Notes about macOS (`macOS 10.13`)

### Resource Links
* [Example Documentation](https://en.wikipedia.org/wiki/Kalman_filter)
```
