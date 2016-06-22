#include "MaximumSubarray.hpp"

#include <algorithm>
using namespace std;

int MaximumSubarray::maxSubArray(vector<int>& nums)
{
  int n = nums.size();
  vector<int> dp(n, 0);
  dp[0] = nums[0];

  for (int i = 1; i < n; i++)
    dp[i] = max(dp[i - 1] + nums[i], nums[i]);

  int ret = dp[0];

  for (int i = 1; i < n; i++)
    ret = max(ret, dp[i]);

  return ret;
}

