# include <iostream>
# include <math.h>

// TODO: pragma once or alternative

// os-specific typdef for internal uuid type

// how to run this with lcm, doing monte carlo trials?
// would require a centralized real-time performance observer
// idea: allow each node 2 modes:
// central clock publishes time out frequently, nodes refer to that as sim time
// to time is published,


class identifier
{
public:
    identifier();
    identifier(char *in, bool time);
    identifier(std::string in, bool time);
    adopt(identifier in); // is this allowed?

    // public accessors and comparators inside the functions #defines handle the appropriate commands
    // how best to attach a time? use a specific type of id and extract it? dedicated age save? how to generate uuid using sim time?
    // constructor for initializing the id
    // constructor for initializing with existing string id (from subscribe message) - possible with system libraries?
    // operator overloading:
    // greater than (compare time) equal to (compare id)
    // swallow
private:

    int test2;
    // private native holder
    //type_fake_t actual_id_; // type_fake_t is typdef'd according to #define
    //std::vector<type_fake_t> vec_; // vector of inherited id's
};


// MEMBERS:
// the id
// time (perhaps immediately extracted from the id after creation) how to use sim time?
// absorbed ids

Init with:
char string, bool (time)
std:string, bool (time)
Nothing, generate new

Operator overloading == to compare if id-new exists

// OPERATORS:
// instantiate-generate
// instantiate-populate with existing
// compare (same as operator overloading ==? need to think about this)
// absorb based on compare logic
// cout
// == logic

// STORY:
// track messages come in, each get thrown into track objects
//
