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

    #if CMAKE_LINUX
    // convert string to c-style char array

    //string str = "some string" ;
    std::cout << "attempting this: " << uuid << std::endl;
    char *cstr = &uuid[0u];
    uuid_parse(cstr, id_);



    #endif

    #if CMAKE_WINDOWS
    std::cout << "attempting this: " << std::endl << uuid << std::endl;
    unsigned char test[20];

    // because we're editing the data fields directly, generate a new one first
    // for good measure in case there are other internal data fields TODO

    std::string one = uuid.substr(0,8);
    std::string two = uuid.substr(9,4);
    std::string thr = uuid.substr(14,4);
    std::string four_0 = uuid.substr(19,2);
    std::string four_1 = uuid.substr(21,2);
    std::string four_2 = uuid.substr(24,2);
    std::string four_3 = uuid.substr(26,2);
    std::string four_4 = uuid.substr(28,2);
    std::string four_5 = uuid.substr(30,2);
    std::string four_6 = uuid.substr(32,2);
    std::string four_7 = uuid.substr(34,2);


    std::cout << one << "-" << two << "-" << thr << "-"
              << four_0 << four_1 << "-"
              << four_2 << four_3 << four_4 << four_5 << four_6 << four_7
              << std::endl;

    testtest(one, id_.Data1);
    testtest(two, id_.Data2);
    testtest(thr, id_.Data3);
    testtest(four_0, id_.Data4[0]);
    testtest(four_1, id_.Data4[1]);
    testtest(four_2, id_.Data4[2]);
    testtest(four_3, id_.Data4[3]);
    testtest(four_4, id_.Data4[4]);
    testtest(four_5, id_.Data4[5]);
    testtest(four_6, id_.Data4[6]);
    testtest(four_7, id_.Data4[7]);

    // what goes in is a string and templated type by ref

    // this approach doesn't seem to work on unsigned char
    // convert four_0 (hex std::string) to unsigned char

    // std::stringstream ss;
    // ss << std::hex << four_0;
    // int hex_as_int;
    // unsigned char aaa;
    // ss >> hex_as_int;
    // aaa = (unsigned char)hex_as_int;


    //unsigned long int aaa = 16;
    //id_.Data1 = aaa;    // normally unsigned long int>8hex, now 8string>8hex>unsigned long int
    //id_.Data2 = bbb;      // normally unsigned short int>4hex, now 4string>4hex>unsigned short int
    //id_.Data3 = 0;      // normally unsigned short int>4hex, now 4string>4hex>unsigned short int
    //id_.Data4[0] = aaa;   // normally unsigned char>2hex, now 2string>2hex>unsigned char
    //id_.Data4[1] = 0;   // normally unsigned char>2hex, now 2string>2hex>unsigned char
    //id_.Data4[2] = 0;   // normally unsigned char>2hex, now 2string>2hex>unsigned char
    //id_.Data4[3] = 0;   // normally unsigned char>2hex, now 2string>2hex>unsigned char
    //id_.Data4[4] = 0;   // normally unsigned char>2hex, now 2string>2hex>unsigned char
    //id_.Data4[5] = 0;   // normally unsigned char>2hex, now 2string>2hex>unsigned char
    //id_.Data4[6] = 0;   // normally unsigned char>2hex, now 2string>2hex>unsigned char
    //id_.Data4[7] = 0;   // normally unsigned char>2hex, now 2string>2hex>unsigned char

    // parse the string into these 11 pieces
    // then convert to hex
    // then



    #endif

    #if CMAKE_MACOS
    // not yet explored
    #endif


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

template <typename T>
void identifier::testtest(std::string &string, T &data) const
{
    // given a hex std::string, convert the the provided data type
    std::stringstream sss;
    sss << std::hex << string;
    if (typeid(T) == typeid(unsigned char))
    {
        // convert to integer before unsigned char
        int hex_as_int;
        sss >> hex_as_int;
        data = (T)hex_as_int;
    }
    else
    {
        sss >> data;
    }
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
