#include "ReverseBits.hpp"

#include <vector>
#include <algorithm>
using namespace std;

uint32_t ReverseBits::reverseBits(uint32_t n)
{
  vector<int> binary(32, 0);

  for (int i = 0; n > 0; i++) {
    binary[i] = n % 2;
    n = n / 2;
  }

  int i = 0, j = 31;

  while (i < j) {
    swap(binary[i], binary[j]);
    i++;
    j--;
  }

  uint32_t base = 1;
  uint32_t result = 0;

  for (int i = 0; i < 32; i++) {
    result += base * binary[i];
    base *= 2;
  }

  return result;
}
