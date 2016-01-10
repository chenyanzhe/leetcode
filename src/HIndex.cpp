#include "HIndex.hpp"

#include <algorithm>
using namespace std;

int HIndex::hIndex(vector<int>& citations)
{
  sort(citations.begin(), citations.end());
  int n = citations.size();
  int i = n - 1;

  while (i >= 0 && citations[i] >= n - i) i--;
  return n - (i + 1);
}
