#include "NumberOfDigitOne.hpp"

// The solution is taken from the following post:
// http://blog.csdn.net/xudli/article/details/46798619
int NumberOfDigitOne::countDigitOne(int n)
{
  int ret = 0;
  for (long d = 1; d <= n; d = d * 10) {
    int a = n / d;
    int b = n % d;
    ret += ((a + 8) / 10) * d + (a % 10 == 1) * (b + 1);
  }
  return ret;
}