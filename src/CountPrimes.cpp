#include "CountPrimes.hpp"

#include <vector>
using namespace std;

int CountPrimes::countPrimes(int n)
{
  int result = 0;
  vector<bool> notPrime(n, false);
  notPrime[1] = true;
  int base = 2;

  while (base * base < n) {
    // marking
    for (int i = base; i * base < n; i++)
      notPrime[i * base] = true;

    // update new base
    int i = base + 1;

    while (i < n && notPrime[i])
      i++;

    base = i;
  }

  for (int i = 1; i < n; i++)
    if (!notPrime[i])
      result++;

  return result;
}
