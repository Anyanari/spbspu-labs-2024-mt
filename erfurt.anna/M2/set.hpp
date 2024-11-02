#include <vector>
#include "circle.hpp"

namespace erfurt
{
  struct Set
  {
    std::string name_;
    size_t setSize_;
    std::vector<Circle> set_;
  };
  std::ostream& operator<<(std::ostream& out, const Set& set);
  FrameRectangle& getFrameRectangle(const Set& set);
  bool operator==(const Set& rsh, const Set& lsh);
}