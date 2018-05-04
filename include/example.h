# include <iostream>
# include <math.h>


class IdClass
{
public:
    int test;
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


// syntax for defining function pointer type:
// typedef void (*functionPtr)(int);
// functionPtr would be the type. using it requires passing int with no return
// functionPtr(14); // using the function pointer


// forward declare WrapperClass for use in typedef and saved owner pointers
class WrapperClass;

// define the method pointer (similar syntax to function pointer above)
typedef void (WrapperClass::*methodPtr)(int);


// declare MemberClass first so core_ can be instantiated using a complete type
class MemberClass
{
public:
    void process_stuff();
    void add_handler(WrapperClass* owner, methodPtr method);
    methodPtr     saved_method_;  // saved callback method pointer
    WrapperClass* saved_owner_;   // saved WrapperClass instantiation pointer
};


class WrapperClass
{
public:
    WrapperClass();
    void set_var(int x);
    void print_var();
    void callback(int x);
    MemberClass core_;
private:
    int x_val_;
};
