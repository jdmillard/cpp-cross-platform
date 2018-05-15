## C++ Cross-Platform CMake Example

The purpose of this repository is to host an example CMake project that works cross-platform. The provided example uses system libraries which is far more interesting and useful than "Hello World". Because system libraries are used, CMake and compiler flags are used to abstract away the API differences between operating systems. This also provides an example of a custom CMake module which is used to find and link libraries that are not natively supported by CMake.

### Some Specifics

Because the native system libraries are used, there are no software dependencies.

The demonstrated functionality centers around creation and storage of [UUID](https://en.wikipedia.org/wiki/Universally_unique_identifier "UUID Wikipedia Page")s (universally unique identifiers) which are ubiquitous in software/tech. Because of their widespread use in many applications, each OS comes with its own shared library (`.so`, `.dll`, etc) which can be used to generate these character strings. However, these libraries have different names and APIs in each OS. Further, they are not supported by CMake which gives us an opportunity to present an example custom module that finds and links the desired library regardless of the current OS.

### Build and Run

Below you will find the build and run instructions for each major operating system.

---
#### Linux

linux notes here (has been tested on version ...)

linux package uuid-dev can be installed with `sudo apt install uuid-dev` (also part of util-linux-ng package)

TODO: clean this up
```bash
cd build/
cmake ..
make
./uuid-run
```

---
#### Windows

If not already installed, install [CMake](https://cmake.org/download/ "Official CMake Website") for Windows and allow the installer to add CMake to `PATH`. In this section there are two sets of instructions for with/without Microsoft Visual Studio.

*Without Visual Studio*

First we'll cover how to build and run without Visual Studio. The Windows UUID [library](https://msdn.microsoft.com/en-us/library/ms923850.aspx "ole32 Module Documentation") comes installed by default, but the link library and header files (which are small files) are only available through the Visual Studio SDK which is [free](https://docs.microsoft.com/en-us/visualstudio/releasenotes/vs2017-relnotes "Visual Studio Community 2017"). You'll need it installed, but no Visual Studio utilities or services will be executed to link, compile, or run *this method*. **Note that the SDK is only needed to provide the header; the resulting executables will work on plain Windows machines without the special SDK installed**. When installing Visual Studio (free version or otherwise), be sure to install the "Desktop development with C++" workload.

This process is the most "Linuxy" because it uses MinGW (Minimalist GNU for Windows). Install [MinGW](http://www.mingw.org/ "Official MinGW Website"). After the installer is set up, launch it, select the required packages, and install (by clicking "Installation > Apply Changes") the following under "Basic Setup":
* `ming32-base` (a basic MinGW installation)
* `ming32-gcc-g++` (the GNU C++ compiler)
* `ming32-gccobjc` (the GNU objective-C compiler)

Now add MinGW to `PATH`:
1. Right click on "This PC" and open "Properties"
1. In the new window click on "Advanced System Settings"
1. In the new window go to the "Advanced" tab then click the "Environment Variables" button
1. In the "System variables" box, select the entry named "Path" then "Edit"
1. In the new window click "New" and type "C:\MinGW\bin" (or your appropriate installation directory)

Test the installation and `PATH` changes by opening a new Windows Command Prompt and typing
```
g++ --version
```

To build and run, enter these commands:
```
cd \<path_to_cloned_repo>\         # swap this with your path, of course
cd build
cmake.exe .. -G "MinGW Makefiles"  # link libraries and generate make files
mingw32-make.exe                   # compile
uuid-run.exe                       # execute the compiled binary file
```
In the future after making changes to code, you should only need to run the last *two* lines from the correct directory. If you run the provided `clean.bat` script, you will have a clean slate and will need the last *three* lines from the correct directory.

*With Visual Studio*

Now we'll cover how to integrate this project with Visual Studio. Note that Visual Studio 2017 supports the creation of CMake projects, but this example avoids using such features because we don't want Visual Studio changing the `CMakeLists.txt` file and ruining our compatibility with Linux and macOS. Rather, we'd like CMake to generate (project/solution/filter files as well as links to libraries). This relegates Visual Studio to editor and debugger.

Warning: Changes to project configuration via Visual Studio will not get "saved". Ideally, perform all library linking and dependency management through CMake.

```
instructions here

TODO
native import to VS (will VS change cmakelists.txt? will this cause chaos?)
use cmake to generate sln and project files?

other notes:
cmake.exe .. -G "MinGW Makefiles"
cmake.exe .. -G "NMake Makefiles"
TODO: make cleanup script for windows
```

---
#### macOS
macOS notes here

### Resource Links
* [ole32 Module (Windows Only)](https://msdn.microsoft.com/en-us/library/ms923850.aspx "ole32 Module Documentation")
* [CoCreateGuid (Windows Only)](https://msdn.microsoft.com/en-us/library/ms886229.aspx "CoCreateGuid Documentation")
