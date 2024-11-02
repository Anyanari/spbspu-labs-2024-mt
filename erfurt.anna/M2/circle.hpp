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
  std::ostream& operator<<(std::ostream& out, const Point& point);

  struct FrameRectangle
  {
    Point sw_;
    Point ne_;
  };

  struct Circle
  {
    Circle(std::string name, size_t radius, size_t x, size_t y):
      name_(name),
      radius_(radius),
      coordinates_(Point{x, y})
      {}

    std::string name_;
    size_t radius_;
    Point coordinates_;
  };
  FrameRectangle& getFrameRectangle(const Circle& circle);
  std::ostream& operator<<(std::ostream& out, const Circle& circle);
}



#endif