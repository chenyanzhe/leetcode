#include "HIndexII.hpp"

int HIndexII::hIndex(vector<int>& citations)
{
  int n = citations.size();
  int h = 0;
  int l = 0;
  int r = n - 1;

  while (l <= r) {
    int m = (l + r) / 2;

    if (citations[m] >= n - m) {
      r = m - 1;
      h = n - m;
    } else {
      l = m + 1;
    }
  }
  return h;
}
