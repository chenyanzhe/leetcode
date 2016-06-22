#include "PowerOfTwo.hpp"

bool PowerOfTwo::isPowerOfTwo(int n)
{
  if (n <= 0)
    return false;

  while ((n & 1) == 0)
    n = n >> 1;

  return n == 1;
}