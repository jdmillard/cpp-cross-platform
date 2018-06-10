#include "identifier.h"

identifier::identifier()
{
    std::cout << "instantiating, generating new id and timestamp" << std::endl;
    generate_time();
    generate_uuid();
}

identifier::identifier(double timestamp)
{
    // when sim time or input report time needs to be used
    // note: provided double needs to be seconds "since epoch"
    std::cout << "instantiating, given a specific time" << std::endl;
    reconstruct_time(timestamp);
    generate_uuid();
}

identifier::identifier(std::string uuid, double timestamp)
{
    // when a specific id and time are known
    // note: provided double needs to be seconds "since epoch"
    std::cout << "instantiating, given a specific id and time" << std::endl;
    reconstruct_time(timestamp);
    reconstruct_uuid(uuid);
}

void identifier::generate_time()
{
    // timestamp
    timestamp_raw_ = std::chrono::high_resolution_clock::now();
    timestamp_ = timestamp_raw_.time_since_epoch();
    // std::chrono::seconds c = std::chrono::duration_cast<std::chrono::seconds>(timestamp_);
    // std::chrono::milliseconds d = std::chrono::duration_cast<std::chrono::milliseconds>(timestamp_);
    // std::chrono::nanoseconds e = std::chrono::duration_cast<std::chrono::nanoseconds>(timestamp_);
    // std::cout << timestamp_.count() << std::endl; // (nanoseconds)
    // std::cout << c.count() << std::endl;
    // std::cout << d.count() << std::endl;
    // std::cout << e.count() << std::endl;
}

void identifier::generate_uuid()
{
    // uuid
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
}

void identifier::reconstruct_time(double seconds)
{
    // convert seconds to integer nanoseconds then to duration
    long long int nanoseconds = seconds*1000000000;
    timestamp_ = std::chrono::system_clock::duration(nanoseconds);

    // TODO: loop back to double and make sure it matches
}

void identifier::reconstruct_uuid(std::string uuid)
{
    // convert string to uuid_t
    std::cout << "TODO: back into uuid object" << std::endl;

    // TODO: loop back to string and make sure it matches
}

std::string identifier::get_uuid_string() const
{
    // provide the identifier in standard string format
    std::stringstream stream;

    #if CMAKE_LINUX
    char id_raw[37];
    uuid_unparse_lower(id_, id_raw);
    stream << id_raw;
    #endif

    #if CMAKE_WINDOWS
    hex_stream(stream, id_.Data1);
    stream << "-";
    hex_stream(stream, id_.Data2);
    stream << "-";
    hex_stream(stream, id_.Data3);
    stream << "-";
    hex_stream(stream, id_.Data4[0]);
    hex_stream(stream, id_.Data4[1]);
    stream << "-";
    hex_stream(stream, id_.Data4[2]);
    hex_stream(stream, id_.Data4[3]);
    hex_stream(stream, id_.Data4[4]);
    hex_stream(stream, id_.Data4[5]);
    hex_stream(stream, id_.Data4[6]);
    hex_stream(stream, id_.Data4[7]);
    #endif

    #if CMAKE_MACOS
    // not yet explored
    #endif

    return stream.str();
}

double identifier::get_time_double() const
{
    // provide the timestamp in standard double format
    // timestamp_.count() is an integer count of nanoseconds
    return timestamp_.count()/(double)1000000000;
}

template <typename T>
void identifier::hex_stream(std::stringstream &stream, T data) const
{
    // given raw data, convert the value to a hex string
    // (compiles for all platforms, only required by Windows)
    stream << std::setfill('0') << std::setw(sizeof(T)*2)
           << std::hex << (int)data;
}

std::ostream& operator<<(std::ostream& stream, const identifier &id)
{
    // when cout is used on the object, return this format:
    // id: a6795f2a-a35b-47e7-b0b0-471fe3ec588b   |   t: 1528572914.2186351 s
    stream << std::setprecision(std::numeric_limits<double>::digits10+2);
    stream << "id: " << id.get_uuid_string();
    stream << "   |   ";
    stream << "t: " << id.get_time_double() << " s";
    return stream;
}
