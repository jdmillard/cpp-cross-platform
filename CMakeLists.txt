cmake_minimum_required(VERSION 2.8)
project(uuid-testing)

# use c++ 11
set(CMAKE_CXX_STANDARD 11)

# for use with custom modules (not supported by CMake)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake/Modules")

# find "universally unique identifier" library
find_package(libuuid REQUIRED)
#find_package(libfoo REQUIRED) # libfoo_INCLUDE_DIRS, libfoo_LIBS
#find_package(libbar REQUIRED) # libbar_INCLUDE_DIRS, libbar_LIBS

# set local and external include directories (allows all #include statements to work)
include_directories(include
  ${libuuid_INCLUDE_DIRS})

# source files to compile into executables
add_executable(uuid-run
  src/main.cpp
  src/example.cpp)

# link libraries to executables
target_link_libraries(uuid-run
  ${libuuid_LIBS})
