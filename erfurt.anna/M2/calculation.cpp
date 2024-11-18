#include "calculation.hpp"
#include "monteCarlo.hpp"

#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <thread>
#include <mutex>
#include <random>


void erfurt::childProcess(int readEnd, int writeEnd)
{
  Calculation calculation;
  size_t seed;
  size_t tries;
  Set set;
  size_t threads;
  read(readEnd, &calculation, sizeof(calculation));
  read(readEnd, &seed, sizeof(seed));
  read(readEnd, &tries, sizeof(tries));
  read(readEnd, &set, sizeof(set));
  read(readEnd, &threads, sizeof(threads));
  double square = getSquare(seed, tries, set, threads);
  Calculation res{calculation.name, true, square};
  write(writeEnd, &res, sizeof(res));
  close(readEnd);
  close(writeEnd);
  exit(0);
}
