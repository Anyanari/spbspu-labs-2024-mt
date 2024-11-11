#include "circle.hpp"

erfurt::Circle::Circle():
  coordinates_({0, 0}),
  name_(),
  radius_(0.0)
  {}

erfurt::Circle::Circle(std::string name, double radius, const Point& coordinate):
  coordinates_(coordinate),
  name_(name),
  radius_(radius)
  {}

erfurt::Circle::Circle(std::string name) :
  name_(name)
{} 

bool erfurt::operator<(const Point& rsh, const Point& lsh)
{
  return (rsh. x_ < lsh.x_ && rsh.y_ <= lsh.y_ || rsh. x_ <= lsh.x_ && rsh.y_ < lsh.y_);
}

std::ostream& erfurt::operator<<(std::ostream& out, const Point& point)
{
  std::ostream::sentry guard(out);
  if (!guard)
  {
    return out;
  }
  out << '(' << point.x_ << ' ' << point.y_ << ')';
  return out;
}

std::ostream& erfurt::operator<<(std::ostream& out, const FrameRectangle& rect)
{
  std::ostream::sentry guard(out);
  if (!guard)
  {
    return out;
  }
  out << rect.sw_ << ' ' << rect.ne_;
  return out;
}

erfurt::FrameRectangle& erfurt::Circle::getFrameRectangle() const
{
  Point ne{coordinates_.x_ + radius_, coordinates_.y_ + radius_};
  Point sw{coordinates_.x_ - radius_, coordinates_.y_ - radius_};
  FrameRectangle frame{sw, ne};
  return frame;
}

std::string erfurt::Circle::getName() const
{
  return name_;
}

bool erfurt::Circle::consistPoint(const Point& point) const
{
  return (coordinates_.x_ - point.x_) * (coordinates_.x_ - point.x_) + 
  (coordinates_.y_ - point.y_) * (coordinates_.y_ - point.y_) <= radius_ * radius_;
}

std::ostream& erfurt::operator<<(std::ostream& out, const Circle& circle)
{
  std::ostream::sentry guard(out);
  if (!guard)
  {
    return out;
  }
  out << circle.radius_ << ' ' << circle.coordinates_ << '\n';
  return out;
}

std::istream& erfurt::operator>>(std::istream& in, Circle& circle)
{
  std::istream::sentry guard(in);
  if (!guard)
  {
    return in;
  }
  std::string name;
  double radius = 0;
  double x = 0, y = 0;
  in >> name >> radius >> x >> y;
  if (in)
  {
    circle = Circle{name, radius, Point{x, y}};
  }
  else
  {
    in.setstate(std::ios::failbit);
  }
  return in;
}

bool erfurt::operator==(const Circle& rsh, const Circle& lsh)
{
  return rsh.getName() == lsh.getName();
}