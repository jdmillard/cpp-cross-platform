# set custom operating system flags

if(UNIX AND NOT(APPLE))
    set(CMAKE_LINUX 1)
else()
    set(CMAKE_LINUX 0)
endif()

if(WIN32)
    set(CMAKE_WINDOWS 1)
else()
    set(CMAKE_WINDOWS 0)
endif()

if(UNIX AND APPLE)
    set(CMAKE_MACOS 1)
else()
    set(CMAKE_MACOS 0)
endif()

# TODO: cause fatal error if OS cannot be detected (if all flags are false)
# and make sure only one is set!
# TODO: add clean status messages for the OS that was detected
