#include "MaximumSubarray.hpp"

int MaximumSubarray::maxSubArray(vector<int>& nums)
{
  vector<int> dp(nums.size(), 0);
  dp[0] = nums[0];
  int max = nums[0];

  for (int i = 1; i < nums.size(); i++) {
    dp[i] = nums[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
    max = dp[i] > max ? dp[i] : max;
  }

  return max;
}
