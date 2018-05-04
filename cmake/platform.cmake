message(STATUS "hi")


# set reliable uniform platform compiler flags
if(UNIX AND NOT(APPLE))
    set(CMAKE_LINUX 1)
else()
    set(CMAKE_LINUX 0)
endif()

if(UNIX AND APPLE)
    set(CMAKE_MACOS 1)
else()
    set(CMAKE_MACOS 0)
endif()

if(WIN32)
    set(CMAKE_WINDOWS 1)
else()
    set(CMAKE_WINDOWS 0)
endif()
# TODO: move platform detection to separate script (can be done with "include" to call a .cmake file)
# TODO: cause fatal error if OS cannot be detected
# TODO: use these flags in the Findlibuuid.cmake script

# TODO: add clean status messages for the OS that was detected and
# cause cmake to stop if OS type could not be recognized
