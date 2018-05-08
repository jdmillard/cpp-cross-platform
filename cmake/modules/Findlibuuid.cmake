# This module finds the Univerally Unique Identifier (UUID) library.
# It defines:
# libuuid_FOUND           (find status)
# libuuid_LIBS            (locations of shared libraries)
# libuuid_INCLUDE_DIRS    (locations of library headers)
# libuuid_VERSION (TODO, look up cmake naming convention for this variable and find out how to extract it)

# module scripts take the conventional from of "Find*.cmake"

# set name used to search for shared library
if(UNIX AND APPLE)
    # macOS
    set(libuuid_LOCAL_NAME System)
    # TODO: (not yet tested)
elseif(UNIX)
    # linux
    set(libuuid_LOCAL_NAME uuid)
    # .so is expected to be in /usr/lib/x86_64-linux-gnu/libuuid.so
endif()

# TODO: change libuuid_LOCAL_NAME to libuuid_LOCAL_LIBRARY_NAME
# TODO: make "/lib /usr/lib and /usr/local/lib" a variable such as libuuid_LOCAL_LIBRARY_PATH
# TODO: make "uuid.h" a variable such as libuuid_LOCAL_HEADER_NAME
# TODO: make "/usr/local/include/uuid and /usr/include/uuid" a variable such as libuuid_LOCAL_HEADER_PATH
# then we'll have:
# libuuid_LOCAL_LIB_NAME
# libuuid_LOCAL_LIB_PATHS
# libuuid_LOCAL_HEADER_NAME
# libuuid_LOCAL_HEADER_PATHS

# find the location of the shared library
find_library(libuuid_LIBS
    NAMES ${libuuid_LOCAL_NAME}
    PATHS /lib /usr/lib /usr/local/lib
    )
# these paths aren't required for linux, another reason to turn these into a variable

# find the location of the library headers
find_path(libuuid_INCLUDE_DIRS uuid.h
    /usr/local/include/uuid
    /usr/include/uuid
    )
# TODO: look up cmake documentation and see if find_path can follow the find_library
# with NAMES \n PATHS

if (libuuid_LIBS AND libuuid_INCLUDE_DIRS)
    set(libuuid_FOUND TRUE)
else ()
    set(libuuid_FOUND FALSE)
endif ()
# TODO: test this failure logic here and below

# manage find status
if (libuuid_FOUND)
    if (NOT libuuid_FIND_QUIETLY)
        # no QUIET argument was passed to find_package
        message(STATUS "Found libuuid.h:  ${libuuid_INCLUDE_DIRS}/uuid.h")
        message(STATUS "Found libuuid.so: ${libuuid_LIBS}")
        # TODO: make tabs align in print statements
        # TODO: get info from shared library such as version information and name (still haven't figured this out)
        # TODO: test the QUIET logic
    endif ()
else ()
    if (libuuid_FIND_REQUIRED)
        message(FATAL_ERROR "Could not find libuuid")
    endif ()
endif ()

# only show libuuid_INCLUDE_DIRS and libuuid_LIBS in the advanced view
mark_as_advanced(
    libuuid_INCLUDE_DIRS
    libuuid_LIBS
    )
