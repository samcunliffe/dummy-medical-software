#include "dummy-medical-software/dummy-medical-software.hpp"
#include <iostream>

int
main()
{
  int result = dummymedicalsoftware::add_one(1);
  std::cout << "1 + 1 = " << result << std::endl;
}
