#ifndef CALCULATION_HPP
#define CALCULATION_HPP

#include <string>

namespace erfurt
{
  struct Calculation
  {
    std::string name;
    bool completed;
    double area;
  };

  void childProcess(int readEnd, int writeEnd);
}

#endif