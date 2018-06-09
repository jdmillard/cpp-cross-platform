#include "identifier.h"

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

    std::cout << " --- test here ---" << std::endl;
    printf("%08lX-%04hX-%04hX-%02hhX%02hhX-%02hhX%02hhX%02hhX%02hhX%02hhX%02hhX",
        id_.Data1, id_.Data2, id_.Data3,
        id_.Data4[0], id_.Data4[1], id_.Data4[2], id_.Data4[3],
        id_.Data4[4], id_.Data4[5], id_.Data4[6], id_.Data4[7]);
    std::cout << std::endl;
    // "%08lX"
    // "%" insert value
    // "0n" left-pads the number with zero with N minimum characters
    // "l" long int
    // "h" short int
    // "hh" signed char
    // "X" hexadecimal integer

    std::string outout = get_string();
    std::cout << outout << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

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

std::string identifier::get_string() const
{
    // provide the identifier in standard string format

    std::stringstream stream123;

    data_to_hex_stream(stream123, id_.Data1);
    stream123 << "-";
    data_to_hex_stream(stream123, id_.Data2);
    stream123 << "-";
    data_to_hex_stream(stream123, id_.Data3);
    stream123 << "-";
    data_to_hex_stream(stream123, id_.Data4[0]);
    data_to_hex_stream(stream123, id_.Data4[1]);
    stream123 << "-";
    data_to_hex_stream(stream123, id_.Data4[2]);
    data_to_hex_stream(stream123, id_.Data4[3]);
    data_to_hex_stream(stream123, id_.Data4[4]);
    data_to_hex_stream(stream123, id_.Data4[5]);
    data_to_hex_stream(stream123, id_.Data4[6]);
    data_to_hex_stream(stream123, id_.Data4[7]);

    // TODO: windows only!
    // TODO: rename stream

    return stream123.str();
}

void identifier::print_uuid()
{
    // remove this function and, instead overload the << operator
    std::cout << "print uuid here" << std::endl;
}

template <typename T>
void identifier::data_to_hex_stream(std::stringstream &stream, T data) const
{
    // what does setfill and setw actually do? why do I need the endl in there?
    // divide this out into multiple lines
    stream << std::setfill('0') << std::setw(sizeof(T)*2) << std::hex << (int)data;
}

std::ostream& operator<<(std::ostream& stream, const identifier &id)
{
    // move definition to cpp
    // see what types the uuid can be converted to
        // Linux:   the unparse command puts to char*
        // Windows: the uuidtostring goes to rpc_cstr
        // macos:
    // test cout with those types
    // turn it into serious behavior with uuid and time
    stream << id.get_string();
    return stream;
}
