#include "DivideTwoIntegers.hpp"

#include <climits>
#include <cstdlib>

int DivideTwoIntegers::divide(int dividend, int divisor)
{
  if (divisor == 1)
    return dividend;

  if ((dividend == INT_MIN && divisor == -1) || divisor == 0)
    return INT_MAX;

  int sign = (dividend > 0 ^ divisor > 0) ? -1 : 1;
  long ret = 0;
  long end = labs((long) dividend);
  long sor = labs((long) divisor);

  while (end >= sor) {
    long temp = sor;
    long power = 1;

    while ((temp << 1) < end) {
      power <<= 1;
      temp <<= 1;
    }

    ret += power;
    end -= temp;
  }

  return sign * ret;
}
