#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <iostream>
#include <string>

namespace erfurt
{
  struct Point
  {
    double x_;
    double y_;
  };
  bool operator<(const Point& rsh, const Point& lsh);
  std::ostream& operator<<(std::ostream& out, const Point& point);
  
  struct FrameRectangle
  {
    Point sw_;
    Point ne_;
  };
  std::ostream& operator<<(std::ostream& out, const FrameRectangle& rect);

  class Circle
  {
  public:
    Circle();
    Circle(std::string name);
    Circle(std::string name, double radius, const Point& coordinate);
    FrameRectangle& getFrameRectangle() const;
    std::string getName() const;
    bool consistPoint(const Point& point) const;
  private:
    friend std::ostream& operator<<(std::ostream& out, const Circle& circle);
    std::string name_;
    double radius_;
    Point coordinates_;
  };
  std::ostream& operator<<(std::ostream& out, const Circle& circle);
  std::istream& operator>>(std::istream& in, Circle& circle);
  bool operator==(const Circle& rsh, const Circle& lsh);
}
#endif