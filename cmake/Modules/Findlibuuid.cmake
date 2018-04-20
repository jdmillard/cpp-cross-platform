# This module finds the Univerally Unique Identifier (UUID) library for UNIX
# systems. It defines:
# liblibuuid_FOUND           (find status)
# libuuid_LIBS            (locations of shared libraries)
# libuuid_INCLUDE_DIRS    (locations of library headers)

# set name used to search for shared library
if(UNIX AND APPLE)
  # macOS
  set(libuuid_LOCAL_NAME System)
  # TODO: (not yet tested)
elseif(UNIX)
  # linux
  set(libuuid_LOCAL_NAME uuid)
endif()

# find the location of the shared library
find_library(libuuid_LIBS
  NAMES ${libuuid_LOCAL_NAME}
  PATHS /lib /usr/lib /usr/local/lib
  )

# find the location of the library headers
find_path(libuuid_INCLUDE_DIRS uuid.h
  /usr/local/include/uuid
  /usr/include/uuid
  )

if (libuuid_LIBS AND libuuid_INCLUDE_DIRS)
  set(libuuid_FOUND TRUE)
else ()
  set(libuuid_FOUND FALSE)
endif ()

# manage find status
if (libuuid_FOUND)
  if (NOT libuuid_FIND_QUIETLY)
    # no QUIET argument was passed to find_package
    message(STATUS "Found libuuid.h:  ${libuuid_INCLUDE_DIRS}/uuid.h")
    message(STATUS "Found libuuid.so: ${libuuid_LIBS}")
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
