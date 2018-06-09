# This module finds the Univerally Unique Identifier (UUID) library.

# the following is defined:
# libuuid_FOUND           (find status)
# libuuid_LIBS            (locations of shared libraries)
# libuuid_INCLUDE_DIRS    (locations of library headers)

# set names and paths used to search for shared library
if(CMAKE_LINUX)
    # library is expected to be    /usr/lib/x86_64-linux-gnu/libuuid.so
    # which is symlinked to        /lib/x86_64-linux-gnu/libuuid.so.1.3.0
    # header is expected to be     /usr/include/uuid/uuid.h
    set(libuuid_LOCAL_LIB_NAME uuid) # TODO: try whole name: libuuid.so
    set(libuuid_LOCAL_LIB_PATHS /lib /usr/lib /usr/local/lib) # TODO: add the whole path including x86... ?
    set(libuuid_LOCAL_HEADER_NAME uuid.h)
    set(libuuid_LOCAL_HEADER_PATHS /usr/include/uuid /usr/local/include/uuid)

elseif(CMAKE_WINDOWS)
    # the link library and header are automatically added by CMake
    # library is expected to be        C:\Windows\System32\ole32.dll
    # the link library is ole32.lib    (no file location, abstracted by SDK)
    # the header is objbase.h          (no file location, abstracted by SDK)

    # set find status to true, print library information, and end this script
    set(libuuid_FOUND TRUE)
    if(NOT libuuid_FIND_QUIETLY)
        # no QUIET argument was passed to find_package
        message(STATUS "Found libuuid.h:  objbase.h")
        message(STATUS "Found libuuid.so: ole32.lib")
    endif()
    return()

elseif(CMAKE_MACOS)
    message(STATUS "from findlibuuid, running on macos") # TODO: remove
    set(libuuid_LOCAL_LIB_NAME System) # (this was found online, TODO: verify that it works)

    # BELOW IS COPIED AND PASTED FROM LINUX, TODO: UPDATE THIS
    # library is expected to be    /usr/lib/x86_64-linux-gnu/libuuid.so
    # which is symlinked to        /lib/x86_64-linux-gnu/libuuid.so.1.3.0
    # header is expected to be     /usr/include/uuid/uuid.h
    set(libuuid_LOCAL_LIB_NAME uuid)
    set(libuuid_LOCAL_LIB_PATHS /lib /usr/lib /usr/local/lib)
    set(libuuid_LOCAL_HEADER_NAME uuid.h)
    set(libuuid_LOCAL_HEADER_PATHS /usr/include/uuid /usr/local/include/uuid)

else()
    # this condition will never happen because it is caught upstream
    message(FATAL_ERROR "os not supported or not detected properly")

endif()

# find the location of the library
find_library(libuuid_LIBS
    NAMES ${libuuid_LOCAL_LIB_NAME}
    PATHS ${libuuid_LOCAL_LIB_PATHS}
    )

# find the location of the library headers
find_path(libuuid_INCLUDE_DIRS
    NAMES ${libuuid_LOCAL_HEADER_NAME}
    PATHS ${libuuid_LOCAL_HEADER_PATHS}
    )

# set find status
if (libuuid_LIBS AND libuuid_INCLUDE_DIRS)
    set(libuuid_FOUND TRUE)
else ()
    set(libuuid_FOUND FALSE)
endif ()

# manage find status
if (libuuid_FOUND)
    if (NOT libuuid_FIND_QUIETLY)
        # no QUIET argument was passed to find_package
        message(STATUS "Found libuuid.h:  ${libuuid_INCLUDE_DIRS}/${libuuid_LOCAL_HEADER_NAME}")
        message(STATUS "Found libuuid.so: ${libuuid_LIBS}")
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

# TODO: test QUIET flag
