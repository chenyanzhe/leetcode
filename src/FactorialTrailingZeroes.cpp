#include "FactorialTrailingZeroes.hpp"

int FactorialTrailingZeroes::trailingZeroes(int n)
{
  int result = 0;

  while (n)
    result += (n /= 5);

  return result;
}
