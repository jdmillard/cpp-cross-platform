#pragma once

#include <vector>
#include <chrono>   // for timestamps
#include <iostream> // for std::ostream and std::cout
#include <sstream>  // for std::stringstream
#include <iomanip>  // std::setfill; std::setw
#include <typeinfo> // for typeid() in templated type logic

#if CMAKE_LINUX
#include <uuid.h>
typedef uuid_t id_raw_t;
#endif

#if CMAKE_WINDOWS
// #include <windows.h>
#include <objbase.h>
typedef GUID id_raw_t;
#endif

#if CMAKE_MACOS
// TODO
#endif

// TODO: typedef identifier class to id_t
// TODO: namespace?
// TODO: switch to <root>/include/<project_name>/<.h files>
// TODO: switch .hpp naming
// TODO: decide on pragmaonce vs ifndef
// TODO: see where const can be used
// TODO: make sure any c arrays are being deleted

class identifier
{
public:
    identifier();
    identifier(double timestamp);
    identifier(std::string uuid, double timestamp);

    std::string get_uuid_string() const;
    double get_time_double() const;

    // operator overloading:
    // greater than (compare time) equal to (compare id)
    // swallow/adopt
        // swallow is to add it to the list of later tracks
        // adopt is to use the new id/timestamp

    // friend means its not a class member (could easily delcare outside the class)
    friend std::ostream& operator<<(std::ostream& stream, const identifier &id);

private:
    void generate_time();
    void generate_uuid();
    void reconstruct_time(double time);
    void reconstruct_uuid(std::string uuid);

    template <typename T>
    void data_to_hex(std::stringstream &stream, T &data) const;

    template <typename T>
    void hex_to_data(std::string &string, T &data) const;

    id_raw_t id_;
    std::vector<id_raw_t> aliases_;
    std::chrono::system_clock::time_point timestamp_raw_;
    std::chrono::system_clock::duration timestamp_;
};

/*
linux:
uuid_compare
https://linux.die.net/man/3/uuid_generate
void uuid_generate(uuid_t out);
void uuid_generate_random(uuid_t out); -- does this come closest to windows?

windows:
IsEqualGUID
https://msdn.microsoft.com/en-us/library/windows/desktop/ms680575(v=vs.85).aspx

// TODO: move these links to the readme resources bullets

macos:

*/
