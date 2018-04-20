cmake_minimum_required(VERSION 2.8)
project(uuid-testing)

# use c++ 11
set(CMAKE_CXX_STANDARD 11)

# for use with custom modules (not supported by CMake)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake/Modules")

# find "universally unique identifier" library
find_package(uuid REQUIRED)
#find_package(Foo REQUIRED) # FOO_INCLUDE_DIRS, FOO_LIBRARIES
#find_package(Boo REQUIRED) # BOO_INCLUDE_DIRS, BOO_LIBRARIES

# temporary variable prints for debugging
message(STATUS "UUID_INCLUDE_DIRS=${UUID_INCLUDE_DIRS}")
message(STATUS "UUID_LIBRARIES=${UUID_LIBRARIES}")

# set local and external include directories (allows all #include statements to work)
include_directories(include
                    ${UUID_INCLUDE_DIRS})

# source files to compile into executables
add_executable(uuid-run
               src/main.cpp
               src/example.cpp)

# link libraries to executables
target_link_libraries(uuid-run
                      ${UUID_LIBRARIES})
