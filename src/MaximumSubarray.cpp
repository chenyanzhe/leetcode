#include "MaximumSubarray.hpp"

#include <algorithm>
using namespace std;

int MaximumSubarray::maxSubArray(vector<int>& nums)
{
  int sz = nums.size();

  if (sz == 0) return 0;

  vector<int> dp(sz, 0);
  dp[0] = nums[0];
  int ret = nums[0];

  for (int i = 1; i < sz; i++) {
    dp[i] = max(dp[i - 1] + nums[i], nums[i]);
    ret = max(dp[i], ret);
  }

  return ret;
}
