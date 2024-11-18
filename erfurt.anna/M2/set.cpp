#include "set.hpp"
#include <algorithm>
#include <iterator>
#include <limits>

erfurt::Set::Set()
{};

erfurt::Set::Set(std::string name, size_t size, std::vector<Circle>& circles) :
  name_(name),
  setSize_(size),
  set_(circles)
{}

erfurt::Set::Set(std::string name) :
  name_(name)
{} 

std::ostream& erfurt::operator<<(std::ostream& out, const Set& set)
{
  std::copy(set.set_.begin(), set.set_.end(), std::ostream_iterator<Circle>(out));
  return out;
}

erfurt::FrameRectangle& erfurt::Set::getFrameRectangle() const
{
  Point ne{0, 0};
  Point sw{std::numeric_limits<size_t>::max(), std::numeric_limits<size_t>::max()};
  for (auto& cir: set_)
  {
    FrameRectangle rec = cir.getFrameRectangle();
    ne = std::max(ne, rec.ne_);
    sw = std::min(sw, rec.sw_);
  }
  FrameRectangle res{sw, ne};
  return res;
}

std::string erfurt::Set::getName() const
{
  return name_;
}

bool erfurt::Set::consistPoint(const Point& point) const
{
  for (auto& circ : set_)
  {
    if (circ.consistPoint(point))
    {
      return true;
    }
  }
  return false;
}

bool erfurt::operator==(const Set& rsh, const Set& lsh)
{
  return rsh.getName() == lsh.getName();
}