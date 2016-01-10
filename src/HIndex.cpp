#include "HIndex.hpp"

#include <algorithm>
using namespace std;

int HIndex::hIndex(vector<int>& citations)
{
  int n = citations.size();

  vector<int> count(n + 1, 0);

  for (auto cite : citations) {
    if (cite <= n) count[cite]++;
    else count[n]++;
  }

  int h   = n;
  int acc = 0;

  while (acc + count[h] < h) {
    acc += count[h];
    h--;
  }

  return h;
}
