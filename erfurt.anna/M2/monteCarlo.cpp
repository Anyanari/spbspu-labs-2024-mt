#include "monteCarlo.hpp"
#include <random>
#include <algorithm>
#include <numeric>
#include <thread>
#include <functional>
#include "circle.hpp" 

void erfurt::countPointsInSet_th(size_t seed, size_t tries, const Set& set, it_t res)
{
  size_t countPoints = 0;
  FrameRectangle rec = set.getFrameRectangle();
  std::mt19937 generator(seed);
  std::uniform_real_distribution< double > x(rec.sw_.x_, rec.ne_.x_);
  std::uniform_real_distribution< double > y(rec.sw_.y_, rec.ne_.y_);
  for (size_t i = 0; i < tries; ++i)
  {
    if (set.consistPoint({x(generator), y(generator)}))
    {
      ++countPoints;
    }
  }
  *res = countPoints;
}

size_t erfurt::countPointsInSet(c_it_t begin, c_it_t end)
{
  return std::accumulate(begin, end, 0);
}

double erfurt::getSquare(size_t seed, size_t numOfTests, const Set& set, size_t countOfThreads)
{
  size_t threads = std::min(static_cast< size_t >(std::thread::hardware_concurrency()) - 1, countOfThreads);
  std::vector< std::thread > ths;
  ths.reserve(threads - 1);
  std::vector< size_t > results(threads, 0);
  size_t per_th = numOfTests / threads;
  size_t last_th = per_th + numOfTests % threads;
  size_t i = 0;
  for (; i < threads - 1; ++i)
  {
    ths.emplace_back(countPointsInSet_th, seed, per_th, set, results.begin() + i);
    seed++;
  }
  countPointsInSet_th(seed, last_th, set, results.begin() + i);
  for (auto&& th : ths)
  {
    th.join();
  }
  size_t countPoints = countPointsInSet(results.cbegin(), results.cend());
  FrameRectangle rec = set.getFrameRectangle();
  return (countPoints * 4 * (rec.ne_.x_ - rec.sw_.x_) * (rec.ne_.y_ - rec.sw_.y_)) / numOfTests;
}