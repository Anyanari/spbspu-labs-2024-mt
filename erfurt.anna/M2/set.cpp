#include "set.hpp"
#include <algorithm>
#include <iterator>
#include <limits>

std::ostream& erfurt::operator<<(std::ostream& out, const Set& set)
{
  std::copy(set.set_.begin(), set.set_.end(), std::ostream_iterator<Circle>(out));
  return out;
}

erfurt::FrameRectangle& erfurt::getFrameRectangle(const Set& set)
{
  Point ne{0, 0};
  Point sw{std::numeric_limits<size_t>::max(), std::numeric_limits<size_t>::max()};
  for (auto& cir: set.set_)
  {
    FrameRectangle rec = getFrameRectangle(cir);
    ne = std::max(ne, rec.ne_);
    sw = std::min(sw, rec.sw_);
  }
  FrameRectangle res{sw, ne};
  return res;
}