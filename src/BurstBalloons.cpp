#include "BurstBalloons.hpp"

int BurstBalloons::maxCoins(vector<int>& nums)
{
  if (nums.empty())
    return 0;

  int sz = nums.size();
  vector<vector<int>> dp(sz, vector<int>(sz, 0));

  for (int l = 1; l <= sz; l++) { // chain length
    for (int i = 0; i <= sz - l; i++) {
      int j = i + l - 1;

      for (int k = i; k <= j; k++) {
        dp[i][j] = max(dp[i][j], getCoins(dp, i, k - 1)
                       + getCoins(dp, k + 1, j)
                       + getCoins(nums, i - 1) * getCoins(nums, k) * getCoins(nums, j + 1));
      }
    }
  }

  return dp[0][sz - 1];
}

int BurstBalloons::getCoins(vector<vector<int>>& dp, int i, int j)
{
  if (i > j || i < 0 || i >= dp.size() || j < 0 || j >= dp.size())
    return 0;
  else
    return dp[i][j];
}

int BurstBalloons::getCoins(vector<int>& nums, int index)
{
  if (index == -1 || index == nums.size())
    return 1;
  else
    return nums[index];
}

