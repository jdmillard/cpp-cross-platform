#include <uuid/uuid.h>
// linux package uuid-dev can be installed with sudo apt install uuid-dev (also part of util-linux-ng package)
// it gets installed to /usr/include/uuid/uuid.h which is on the default include path
// move these comments to a dependencies section of readme.md

#include "example.h"


int main(int argc, char **argv)
{

  // new UUID experiments

  std::cout << "starting" << std::endl;
  std::cout << std::endl;

  uuid_t allocated; // uuid type

  int aaa = 6;
  uuid_generate(allocated);
  aaa = uuid_is_null(allocated);
  std::cout << aaa << std::endl;

  std::cout << std::endl << std::endl;

  // documentation as well as other links for uuid library:
  //https://linux.die.net/man/3/uuid_generate

  // if the default uuid libraries can be managed from the custom module so that
  // only the #include is needed, we do #DEFINE compiler logic for building
  // a uuid class and/or custom type struct which will abstract away the
  // platform dependent API

  // BELOW IS ARTIFACTS OF INHERITED STRUCTURE

  // instantiate the wrapper class
  WrapperClass shell_object;


  std::cout << "terminating main" << std::endl;
} // end of main
