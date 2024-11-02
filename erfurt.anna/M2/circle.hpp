#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <iostream>
#include <string>

namespace erfurt
{
  struct Point
  {
    size_t x_;
    size_t y_;
  };
  bool operator<(const Point& rsh, const Point& lsh);
  std::ostream& operator<<(std::ostream& out, const Point& point);
  
  struct FrameRectangle
  {
    Point sw_;
    Point ne_;
  };
  std::ostream& operator<<(std::ostream& out, const FrameRectangle& rect);

  struct Circle
  {
    std::string name_;
    size_t radius_;
    Point coordinates_;
  };
  FrameRectangle& getFrameRectangle(const Circle& circle);
  std::ostream& operator<<(std::ostream& out, const Circle& circle);
  std::istream& operator>>(std::istream& in, Circle& circle);
  bool operator==(const Circle& rsh, const Circle& lsh);
}
#endif