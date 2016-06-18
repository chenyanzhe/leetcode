#include "CountingBits.hpp"

vector<int> CountingBits::countBits(int num)
{
  vector<int> ret(num + 1, 0);

  if (num == 0) {
    return ret;
  }

  ret[1] = 1;

  for (int i = 2; i <= num; i++) {
    ret[i] = (i & 0x1) ? ret[i / 2] + 1 : ret[i / 2];
  }

  return ret;
}
