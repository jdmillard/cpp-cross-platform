#pragma once

#include <vector>
#include <chrono>

#if CMAKE_LINUX
#include <uuid.h>
typedef uuid_t id_raw_t;
#endif

#if CMAKE_MACOS
// TODO
#endif

#if CMAKE_WINDOWS
//#include <windows.h> // this seems to just work, but is not required (but does it work without VS installed?)
#include <objbase.h> // this seems to just work thanks to cmake adding the windows sytem include directories (but does it work without VS installed?)... move to other header
typedef GUID id_raw_t;
#endif

// todo: typedef identifier class to id_t

class identifier
{
public:
    identifier();
    // identifier(char *in, bool time);
    // identifier(std::string in, bool time);
    // adopt(identifier in); // is this allowed?

    // public accessors and comparators inside the functions #defines handle the appropriate commands
    // how best to attach a time? use a specific type of id and extract it? dedicated age save? how to generate uuid using sim time?
    // constructor for initializing the id
    // constructor for initializing with existing string id (from subscribe message) - possible with system libraries?
    // operator overloading:
    // greater than (compare time) equal to (compare id)
    // swallow

private:
    void generate_uuid();
    void print_uuid();

    id_raw_t id_;
    std::chrono::milliseconds timestamp_;
    std::vector<id_raw_t> aliases_;
    // TODO: time
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
