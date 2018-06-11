#include <iostream>
#include "identifier.h"

// TODO: test out binaries on clean windows
// TODO: test building on clean windows, confirm that the SDK is required

int main(int argc, char **argv)
{
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
