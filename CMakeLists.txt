cmake_minimum_required(VERSION 2.8)
project(uuid-testing)
# rename project

# use c++ 11
set(CMAKE_CXX_STANDARD 11)

# set reliable platform flags
include(cmake/platform.cmake)

# add path for local modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake/modules")

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

target_compile_definitions(uuid-run PRIVATE
    CMAKE_LINUX=${CMAKE_LINUX}
    CMAKE_MACOS=${CMAKE_MACOS}
    CMAKE_WINDOWS=${CMAKE_WINDOWS})
# TODO: see if these definitions are available to headers

# for printing all CMAKE variables (not all definitions?)
# get_cmake_property(_variableNames VARIABLES)
# list (SORT _variableNames)
# foreach (_variableName ${_variableNames})
#     message(STATUS "${_variableName}=${${_variableName}}")
# endforeach()
