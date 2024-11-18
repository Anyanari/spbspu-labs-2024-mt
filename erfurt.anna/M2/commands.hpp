#include "set.hpp"
#include "circle.hpp"
#include "calculation.hpp"

namespace erfurt
{
  void createCircle(std::vector<Circle>& circles, std::istream& in);
  void createSet(std::vector<Set>& sets, const std::vector<Circle>& circles, std::istream& in);
  void showCircle(const std::vector<Circle>& circles, std::istream& in, std::ostream& out);
  void showSet(const std::vector<Set>& sets, std::istream& in, std::ostream& out);
  void frameCircle(const std::vector<Circle>& circles, std::istream& in, std::ostream& out);
  void frameSet(const std::vector<Set>& sets, std::istream& in, std::ostream& out);
  void area(std::vector<Calculation>& calc, std::vector<Set>& set, size_t seed, size_t threads, size_t tries, std::istream& in);
  void status(std::vector<Calculation>& calc, std::istream& in, std::ostream& out);
} 
