#include <iostream>
#include <thread>
#include <mutex>
#include <unistd.h> // for sleep (does not work on Windows)
#include "identifier.h"

// TODO: test out binaries on clean windows
// TODO: test building on clean windows, confirm that the SDK is required

std::mutex global_m;
int global_i = 0;

// TODO: switch to std::lock_guard which is exception safe

void makeACallFromPhoneBooth(double seconds, int id)
{
    usleep(1000000*seconds);
    global_m.lock();

    //man gets a hold of the phone booth door and locks it. The other men wait outside
    //man happily talks to his wife from now....
    std::cout << global_i << " Hello Wife from " << id << std::endl;
    global_i++;
    //no other thread can access variable i until m.unlock() is called
    //...until now, with no interruption from other men
    global_m.unlock();
    //man lets go of the door handle and unlocks the door
}

int main(int argc, char **argv)
{

    std::cout << "THREAD TEST HERE vvvvvvvvvvvvv" << std::endl;
    double seconds = 1.5;
    usleep(1000000*seconds);
    std::cout << "wait done" << std::endl;

    //This is the main crowd of people uninterested in making a phone call

    //man1 leaves the crowd to go to the phone booth
    std::thread man1(makeACallFromPhoneBooth, 3, 1);
    //Although man2 appears to start second, there's a good chance he might
    //reach the phone booth before man1
    std::thread man2(makeACallFromPhoneBooth, 2, 2);
    //And hey, man3 also joined the race to the booth
    std::thread man3(makeACallFromPhoneBooth, 1, 3);



    std::cout << "all threads kicked off, rolling on" << std::endl;

    man1.join();//man1 finished his phone call and joins the crowd
    man2.join();//man2 finished his phone call and joins the crowd
    man3.join();//man3 finished his phone call and joins the crowd

    return 0;











    // example uuid format:
    // a6795f2a-a35b-47e7-b0b0-471fe3ec588b
    identifier object;
    std::cout << object << std::endl;
    object = identifier();
    std::cout << object << std::endl << std::endl;

    double timestamp = 1528600401.9890461;
    identifier object2(timestamp);
    std::cout << object2 << std::endl << std::endl;

    std::string test_input = "a6795f2a-a35b-47e7-b0b0-471fe3ec588b";
    identifier object3(test_input, timestamp);
    std::cout << object3 << std::endl << std::endl;

    std::cout << "terminating main" << std::endl;
}
