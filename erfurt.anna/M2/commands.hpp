#include "set.hpp"
#include "circle.hpp"

namespace erfurt
{
  void createCircle(std::vector<Circle>& circles, std::istream& in);
  void createSet(std::vector<Set>& sets, const std::vector<Circle>& circles, std::istream& in);
  void showCircle(const std::vector<Circle>& circles, std::istream& in, std::ostream& out);
  void showSet(const std::vector<Set>& sets, std::istream& in, std::ostream& out);
  void frameCircle(const std::vector<Circle>& circles, std::istream& in, std::ostream& out);
  void frameSet(const std::vector<Set>& sets, std::istream& in, std::ostream& out);
} 
