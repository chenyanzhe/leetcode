#include "MaximumSubarray.hpp"

int MaximumSubarray::maxSubArray(vector<int>& nums)
{
  int sz = nums.size();

  if (sz == 0) return 0;

  vector<int> dp(sz, 0);
  dp[0] = (nums[0] <= 0) ? 0 : nums[0];

  for (int i = 1; i < sz; i++) {
    int val = dp[i - 1] + nums[i];
    dp[i] = (val <= 0) ? 0 : val;
  }

  int ret = nums[0];
  for (int i = 0; i < sz; i++) {
    if (dp[i] == 0 && ret < nums[i]) {
      ret = nums[i];
    } else if (dp[i] > 0 && ret < dp[i]) {
      ret = dp[i];
    }
  }

  return ret;
}
