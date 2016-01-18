#include "LongestIncreasingSubsequence.hpp"

int LongestIncreasingSubsequence::lengthOfLIS(vector<int>& nums)
{
  int sz = nums.size();

  if (sz == 0) {
    return 0;
  }

  int ret = 1;
  vector<int> dp(sz, 1);

  for (int i = 1; i < sz; i++) {
    for (int j = 0; j < i; j++) {
      if (nums[i] > nums[j] && dp[j] + 1 > dp[i]) {
        dp[i] = dp[j] + 1;

        if (ret < dp[i]) {
          ret = dp[i];
        }
      }
    }
  }

  return ret;
}