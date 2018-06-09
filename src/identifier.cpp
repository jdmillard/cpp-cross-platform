#include "identifier.h"

identifier::identifier()
{
    std::cout << "instantiating identifier object" << std::endl;

    generate_uuid();

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
    uuid_generate(id_);
    #endif

    #if CMAKE_WINDOWS
    std::cout << "running on windows" << std::endl; // temporary
    CoCreateGuid(&id_);
    #endif

    #if CMAKE_MACOS
    std::cout << "running on mac" << std::endl; // temporary
    // TODO: not yet tested
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
    // put before the call to creation
}

std::string identifier::get_string() const
{
    // provide the identifier in standard string format
    // TODO: add a check to make sure the string isn't empty

    #if CMAKE_LINUX

    char test2[37];
    uuid_unparse_lower(id_, test2);

    std::stringstream stream123;
    stream123 << test2;

    return stream123.str();
    #endif

    #if CMAKE_WINDOWS
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
    return stream123.str();
    #endif

    #if CMAKE_MACOS
    // not yet explored
    #endif
}

template <typename T>
void identifier::data_to_hex_stream(std::stringstream &stream, T data) const
{
    // given raw data, convert the value to a hex string
    // (compiles for all platforms, only required by Windows)
    stream << std::setfill('0') << std::setw(sizeof(T)*2)
           << std::hex << (int)data;
}

std::ostream& operator<<(std::ostream& stream, const identifier &id)
{
    // TODO: why is stream passed by reference, but then also returned?
    stream << id.get_string();
    return stream;
}
