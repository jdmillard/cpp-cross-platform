#include "identifier.h"

identifier::identifier()
{
    std::cout << "instantiating, using system clock" << std::endl;

    generate_time();
    generate_uuid();
}

identifier::identifier(double sim_time)
{
    // in non-real-time execution, a sim time will be used for the timestamp
    // also, could be used in the case that a report timestamp needs to be used
    std::cout << "instantiating, given a sim time" << std::endl;
    std::cout << sim_time << std::endl;
    // why would I want this form of instantiation?

    // note: sim clock needs to provide the time since epoch format as a double

    // parse the provided double into duration since epoch (to match system-generated setup)
    // TODO: create a function called reconstruct_time? (could be used here and in the string versions)
    // TODO: the other forms would use reconstruct_uuid as well.
    generate_uuid();
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
