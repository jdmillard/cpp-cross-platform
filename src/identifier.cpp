#include "identifier.h"

#include <iostream> // for debugging, TODO: remove after cout not needed

identifier::identifier()
{
    std::cout << "instantiating identifier object" << std::endl;

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
    std::cout << "running on linux" << std::endl; // temporary
    id_raw_t allocated;
    uuid_generate(allocated);
    uuid_generate(id_);
    #endif

    #if CMAKE_WINDOWS
    std::cout << "running on windows" << std::endl; // temporary
    id_raw_t allocated;
    CoCreateGuid(&allocated);
    CoCreateGuid(&id_);
    #endif

    #if CMAKE_MACOS
    std::cout << "running on mac" << std::endl; // temporary
    // TODO
    #endif

    // timestamp
    timestamp_raw_ = std::chrono::high_resolution_clock::now();
    timestamp_ = timestamp_raw_.time_since_epoch();

    std::chrono::system_clock::duration b = timestamp_;
    std::chrono::seconds c = std::chrono::duration_cast<std::chrono::seconds>(b);
    std::chrono::milliseconds d = std::chrono::duration_cast<std::chrono::milliseconds>(b);
    std::chrono::nanoseconds e = std::chrono::duration_cast<std::chrono::nanoseconds>(b);

    std::cout << b.count() << std::endl;
    std::cout << c.count() << std::endl;
    std::cout << d.count() << std::endl;
    std::cout << e.count() << std::endl;

    // TODO:
    // use the raw time_point and duration types for members
    // for operator overloading, convert to seconds with double precision
}

void identifier::print_uuid()
{
    // remove this function and, instead overload the << operator
    std::cout << "print uuid here" << std::endl;
}
