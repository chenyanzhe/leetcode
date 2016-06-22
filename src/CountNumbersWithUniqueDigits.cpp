#include "CountNumbersWithUniqueDigits.hpp"

#include <algorithm>
using namespace std;

int CountNumbersWithUniqueDigits::countNumbersWithUniqueDigits(int n)
{
  if (n == 0)
    return 1;

  if (n == 1)
    return 10;

  int ret = 10;
  int acc = 9;

  for (int i = 2; i <= min(n, 10); i++) {
    acc *= (10 - i + 1);
    ret += acc;
  }

  return ret;
}
