#pragma once

#include <vector>
#include <chrono> // for timestamps
#include <iostream>
#include <sstream> // for std::stringstream
#include <iomanip> // std::setfill; std::setw

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

class identifier
{
public:
    identifier();
    // identifier(char *in, double time);
    // identifier(std::string in, double time); // or char*
    // adopt(identifier in); // is this allowed?

    std::string get_string() const;

    // public accessors and comparators inside the functions #defines handle the appropriate commands
    // how best to attach a time? use a specific type of id and extract it? dedicated age save? how to generate uuid using sim time?
    // constructor for initializing the id
    // constructor for initializing with existing string id (from subscribe message) - possible with system libraries?
    // operator overloading:
    // greater than (compare time) equal to (compare id)
    // swallow/adopt
        // swallow is to add it to the list of later tracks
        // adopt is to use the new id/timestamp

    // friend means its not a class member (could easily delcare outside the class)
    friend std::ostream& operator<<(std::ostream& stream, const identifier &id);

private:
    void generate_uuid();

    // TODO: data passed by ref?
    template <typename T>
    void hex_stream(std::stringstream &stream, T data) const;

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

macos:

*/
