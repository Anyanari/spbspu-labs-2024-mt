#include "circle.hpp"

bool erfurt::operator<(const Point& rsh, const Point& lsh)
{
  return (rsh. x_ < lsh.x_ && rsh.y_ <= lsh.y_ || rsh. x_ <= lsh.x_ && rsh.y_ < lsh.y_);
}

std::ostream& erfurt::operator<<(std::ostream& out, const Point& point)
{
  out << '(' << point.x_ << ' ' << point.y_ << ')';
  return out;
}

std::ostream& erfurt::operator<<(std::ostream& out, const FrameRectangle& rect)
{
  out << rect.sw_ << ' ' << rect.ne_;
  return out;
}


erfurt::FrameRectangle& erfurt::getFrameRectangle(const Circle& circle)
{
  Point ne{circle.coordinates_.x_ + circle.radius_, circle.coordinates_.y_ + circle.radius_};
  Point sw{circle.coordinates_.x_ - circle.radius_, circle.coordinates_.y_ - circle.radius_};
  FrameRectangle frame{sw, ne};
  return frame;
}

std::ostream& erfurt::operator<<(std::ostream& out, const Circle& circle)
{
  out << circle.radius_ << ' ' << circle.coordinates_ << '\n';
  return out;
}