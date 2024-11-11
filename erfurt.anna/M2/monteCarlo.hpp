#ifndef MONTECARLO_HPP
#define MONTECARLO_HPP

#include <vector>
#include <iterator>
#include "set.hpp"

namespace erfurt
{
  using data_t = std::vector< size_t >;
  using it_t = data_t::iterator;
  using c_it_t = data_t::const_iterator;
  
  void countPointsInSet_th(size_t seed, size_t tries, const Set& set, it_t res);
  size_t countPointsInSet(c_it_t begin, c_it_t end);
  double getSquare(size_t seed, size_t tries, const Set& set, size_t countOfThreads);
}

#endif