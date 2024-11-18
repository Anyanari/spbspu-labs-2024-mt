#include <vector>
#include "circle.hpp"

namespace erfurt
{
  class Set
  {
  public:
    Set();
    Set(std::string name);
    Set(std::string name, size_t size, std::vector<Circle>& circles);
    FrameRectangle& getFrameRectangle() const;
    std::string getName() const;
    bool consistPoint(const Point& point) const;
  private:
    friend std::ostream& operator<<(std::ostream& out, const Set& set);
    std::string name_;
    size_t setSize_;
    std::vector<Circle> set_;
  };
  std::ostream& operator<<(std::ostream& out, const Set& set);
  bool operator==(const Set& rsh, const Set& lsh);
}