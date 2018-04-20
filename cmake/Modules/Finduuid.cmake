find_package(PkgConfig REQUIRED)

pkg_search_module(UUID REQUIRED uuid)

# calling find_package on a name that CMake does not support will issue a search for
# Find<package>.cmake in the modules path, so we create this file and add
# repo-root/cmake/Modules to the modules path

# the idea here is to write a cross-platform script that populates necessary
# path variables (rather than using pkg_search_module and PkgConfig)
# figure out the naming, what can be renamed, etc
# if there is sufficient renaming power here, can this be used to manage
# unique libraries on different platforms, abstracted away into one here?
# what needs to be done so that the REQUIRED works as intended in the level above?



# LINKS:
# example script are
# https://gitlab.cern.ch/dmc/cmake-modules/blob/302a0ac6b59edb1a2e3319de8d81780eec3087e9/modules/FindUUID.cmake
# OR
# https://nanohub.org/infrastructure/rappture-runtime/svn/trunk/gdcm-2.4.1/CMake/FindUUID.cmake
# OR
# https://gitlab.kitware.com/cmb/cmb/blob/bbee5436ea055136947c6249750832f37427c2af/Source/CMake/FindUUID.cmake
#
#
# more details found here:https://gitlab.cern.ch/dmc/cmake-modules/blob/302a0ac6b59edb1a2e3319de8d81780eec3087e9/modules/FindUUID.cmake
# https://cmake.org/Wiki/CMake:How_To_Find_Libraries

# also, since we are trying to mimick find_package, try to supply the basic expected outputs:
# https://cmake.org/cmake/help/v3.0/command/find_package.html
