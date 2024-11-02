#include <vector>
#include  "circle.hpp"

namespace erfurt
{
  struct Set
  {
    std::vector<Circle> set_;
    std::string name_;
    size_t setSize_;
  };
  std::ostream& operator<<(std::ostream& out, const Set& set);
  FrameRectangle& getFrameRectangle(const Set& set);
}