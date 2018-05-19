#include <iostream> // TODO: remove after cout is no longer needed
#include "identifier.h"

identifier::identifier()
{
    std::cout << "instantiated identifier" << std::endl;

    generate_uuid();
    print_uuid();

    // IDs FOR TRACKS:
    // various unsigned chars come through subscription (the first one is the track id and subsequent ones are adopted ids)
    // throw all of these into a new id class
    // compare local id classes to see if already equal (return bool)
    // after additional state checks, etc, once confirmed the same, a way to merge

    // if timestamps are to be extracted from the UUID, use this post:
    // https://stackoverflow.com/a/15179513
    // and create a test that makes sure the time extraction method works (test will have a hardcoded UUID value)

}

void identifier::generate_uuid()
{
    #if CMAKE_LINUX
    std::cout << "running on linux" << std::endl;
    id_raw_t allocated;
    uuid_generate(allocated);
    std::cout << uuid_is_null(allocated) << std::endl;
    #endif

    #if CMAKE_WINDOWS
    std::cout << "running on windows" << std::endl;
    id_raw_t allocated;
    CoCreateGuid(&allocated);
    #endif

    #if CMAKE_MACOS
    std::cout << "running on mac" << std::endl;
    // TODO
    #endif
}

void identifier::print_uuid()
{
    std::cout << "print uuid here" << std::endl;
}
