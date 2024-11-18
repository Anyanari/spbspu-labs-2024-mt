#include "commands.hpp"
#include <iterator>
#include <algorithm>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <cmath>
#include <iomanip>
#include "calculation.hpp"
//#include <streamGuard.hpp>;

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
  if (std::find(sets.cbegin(), sets.cend(), Set(name)) != sets.cend())
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
    auto iter = std::find(circles.cbegin(), circles.cend(), Circle(circ));
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

void erfurt::showCircle(const std::vector<Circle>& circles, std::istream& in, std::ostream& out)
{
  std::string name;
  in >> name;
  auto iter = std::find(circles.cbegin(), circles.cend(), Circle(name));
  if (iter == circles.cend())
  {
    throw std::logic_error("This circle not exist");
  }
  else
  {
    out << *iter;
  }
}

void erfurt::showSet(const std::vector<Set>& sets, std::istream& in, std::ostream& out)
{
  std::string name;
  in >> name;
  auto iter = std::find(sets.cbegin(), sets.cend(), Set(name));
  if (iter == sets.cend())
  {
    throw std::logic_error("This set not exist");
  }
  else
  {
    out << *iter;
  }
}

void erfurt::frameCircle(const std::vector<Circle>& circles, std::istream& in, std::ostream& out)
{
  std::string name;
  in >> name;
  auto iter = std::find(circles.cbegin(), circles.cend(), Circle{name});
  if (iter == circles.cend())
  {
    throw std::logic_error("This circle not exist");
  }
  else
  {
    out << iter->getFrameRectangle();
  }
}

void erfurt::frameSet(const std::vector<Set>& sets, std::istream& in, std::ostream& out)
{
  std::string name;
  in >> name;
  auto iter = std::find(sets.cbegin(), sets.cend(), Set{name});
  if (iter == sets.cend())
  {
    throw std::logic_error("This set not exist");
  }
  else
  {
    out << iter->getFrameRectangle();
  }
}

 void erfurt::area(std::vector<Calculation>& calc, std::vector<Set>& set, size_t seed, size_t threads, size_t tries, std::istream& in)
 {
    std::string calcName;
    std::string setName;
    size_t threads;
    size_t tries;
    in >> calcName >> setName >> threads >> tries;
    Calculation calculation{calcName, false, 0.0};
    if (std::find(calc.cbegin(), calc.cend(), Calculation{calcName}) != calc.cend())
    {
      throw std::logic_error("This calculation already exist");
    }
    auto iter = std::find(set.cbegin(), set.cend(), Set{setName});
    if (iter == set.cend())
    {
      throw std::logic_error("This set not exist");
    }
    calc.push_back(calculation);
    int pipeFds[2];
    pid_t pid;
    
    if (pipe(pipeFds) == -1)
    {
      perror("pipe");
      return ;
    }

    pid = fork();
    if (pid == -1) 
    {
      perror("fork");
      return ;
    }

    if (pid == 0) 
    {  
      close(pipeFds[1]); 
      childProcess(pipeFds[0], pipeFds[1]);
    } 
    else 
    {
      close(pipeFds[0]); 
      write(pipeFds[1], &calculation, sizeof(calculation));
      write(pipeFds[1], &seed, sizeof(seed));
      write(pipeFds[1], &tries, sizeof(tries));
      write(pipeFds[1], &iter, sizeof(iter));
      write(pipeFds[1], &threads, sizeof(threads));
      close(pipeFds[1]);
      read(pipeFds[0], &calculation, sizeof(calc));
      close(pipeFds[0]);
    }
 }

 void erfurt::status(std::vector<Calculation>& calc, std::istream& in, std::ostream& out)
 {
    std::string calcName;
    in >> calcName;
    auto iter = std::find(calc.cbegin(), calc.cend(), Calculation{calcName});
    if (iter == calc.cend())
    {
      throw std::logic_error("This process is not exist");
    }
    if (iter->completed)
    {
      out << out.fixed << std::setprecision(3) << iter->area;
    }
    else
    {
      out << "<IN PROGRESS>";
    }
 }