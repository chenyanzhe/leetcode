#include "ReverseInteger.hpp"

#include <climits>
using namespace std;

int ReverseInteger::reverse(int x)
{
  long res = 0;

  while (x) {
    res = res * 10 + x % 10;
    x /= 10;
  }

  return (res < INT_MIN || res > INT_MAX) ? 0 : res;
}
