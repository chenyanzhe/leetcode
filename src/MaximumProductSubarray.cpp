#include "MaximumProductSubarray.hpp"

#include <algorithm>
using namespace std;

int MaximumProductSubarray::maxProduct(vector<int>& nums)
{
  int sz = nums.size();
  if (sz == 0) return 0;

  int minNow, maxNow, maxGlobal;
  minNow = maxNow = maxGlobal = nums[0];

  for (int i = 1; i < sz; i++) {
    if (nums[i] >= 0) {
      maxNow = max(maxNow * nums[i], nums[i]);
      minNow = min(minNow * nums[i], nums[i]);
    } else {
      int _maxNow = maxNow;
      maxNow = minNow * nums[i];
      minNow = min(_maxNow * nums[i], nums[i]);
    }

    maxGlobal = max(maxGlobal, maxNow);
  }

  return maxGlobal;
}
