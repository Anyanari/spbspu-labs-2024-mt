#include "function.hpp"
#include <iterator>
#include <algorithm>

void erfurt::createCircle(std::vector<Circle>& circles, std::istream& in)
{
  Circle circle;
  in >> circle;
  if (std::find(circles.begin(), circles.end(), circle) != circles.end())
  {
    throw std::logic_error("This circle alredy exist");
  }
  else
  {
    circles.push_back(circle);
  }
}

void erfurt::createSet(std::vector<Set>& sets, const std::vector<Circle>& circles, std::istream& in)
{
  std::string name;
  in >> name;
  if (std::find(sets.cbegin(), sets.cend(), Set{name}) != sets.cend())
  {
    throw std::logic_error("This set already exist");
    return;
  }
  size_t setSize = 0;
  in >> setSize;
  std::vector<Circle> temp;
  temp.reserve(setSize);
  for (size_t i = 0; i < setSize; ++i)
  {
    std::string circ;
    in >> circ;
    auto iter = std::find(circles.cbegin(), circles.cend(), Circle{circ});
    if (iter == circles.cend())
    {
      throw std::logic_error("This circle not exist");
      return;
    }
    else
    {
      temp.push_back(*iter);
    }
  }
  sets.push_back(Set{name, setSize, temp});
}