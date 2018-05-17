#pragma once

#if CMAKE_LINUX
#include <uuid.h>
#endif

#if CMAKE_MACOS
// TODO
#endif

#if CMAKE_WINDOWS
//#include <windows.h> // this seems to just work, but is not required (but does it work without VS installed?)
#include <objbase.h> // this seems to just work thanks to cmake adding the windows sytem include directories (but does it work without VS installed?)... move to other header
#endif

// os-specific typdef for internal uuid type (in block above)
// example typedef:
// typedef existing new;

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
    int test2_;
    // private native holder
    //type_fake_t actual_id_; // type_fake_t is typdef'd according to #define
    //std::vector<type_fake_t> vec_; // vector of inherited id's
};


// MEMBERS:
// the id
// time (perhaps immediately extracted from the id after creation) how to use sim time?
// absorbed ids

// Init with:
// char string, bool (time)
// std:string, bool (time)
// Nothing, generate new
//
// Operator overloading == to compare if id-new exists
// see what types of functions each platform library provides

/*
linux:
uuid_compare
https://linux.die.net/man/3/uuid_generate

windows:
IsEqualGUID
https://msdn.microsoft.com/en-us/library/windows/desktop/ms680575(v=vs.85).aspx

macos:


*/

// OPERATORS:
// instantiate-generate
// instantiate-populate with existing
// compare (same as operator overloading ==? need to think about this)
// absorb/adopt other identifier+timer (possible to have input object?)
// cout

// STORY:
// track messages come in with single uuid+timestap, each get thrown into track objects
//
