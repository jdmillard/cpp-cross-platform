#include <uuid.h>
// linux package uuid-dev can be installed with sudo apt install uuid-dev (also part of util-linux-ng package)
// it gets installed to /usr/include/uuid/uuid.h which is on the default include path
// move these comments to a dependencies section of readme.md

// TODO:
// add cleanup script in build folder, consolidate .gitignore files

#include "example.h"

// typedef existing new;
typedef uuid_t fake_t;

int main(int argc, char **argv)
{



    //#ifdef (alternative)
    #if CMAKE_LINUX
    std::cout << "running on linux" << std::endl;
    #endif

    #if CMAKE_MACOS
    std::cout << "running on mac" << std::endl;
    #endif

    #if CMAKE_WINDOWS
    std::cout << "running on windows" << std::endl;
    #endif

    // TODO: test these flags on the platforms
    // TODO: use these flags in dedicated header for include statements


    // std::cout << UNIT_TESTING << std::endl;

    // new UUID experiments

    std::cout << "starting" << std::endl;
    std::cout << std::endl;

    fake_t allocated; // uuid type

    int aaa = 6;
    uuid_generate(allocated);
    aaa = uuid_is_null(allocated);
    std::cout << aaa << std::endl;

    std::cout << std::endl << std::endl;

    // make an id class (think of good name for this)
    // there will be a fake_t member, everything revolves around this member
    // operator. the fake_t member will point to the type based on the system
    // the comparison functions will be compiler-defined based on the library
    // system-level library differences will be abstracted away
    // I'm not sure what to do about pointers

    // PLAN: use unix/windows/apple libraries for uuid comparison
    // which means the high-level class needs pounddefine to
    // force usage of naitive lib functions

    // documentation as well as other links for uuid library:
    //https://linux.die.net/man/3/uuid_generate

    // if the default uuid libraries can be managed from the custom module so that
    // only the #include is needed, we do #DEFINE compiler logic for building
    // a uuid class and/or custom type struct which will abstract away the
    // platform dependent API

    // BELOW IS ARTIFACTS OF INHERITED STRUCTURE

    // instantiate the wrapper class
    WrapperClass shell_object;


    std::cout << "terminating main" << std::endl;
} // end of main
