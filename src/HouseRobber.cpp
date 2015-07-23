#include "HouseRobber.hpp"

#include <algorithm>
using namespace std;

int HouseRobber::rob(vector<int>& nums)
{
  int n = nums.size();
  if (n <= 0) return 0;
  if (n == 1) return nums[0];

  vector<int> dp(n, 0);
  dp[0] = nums[0]; dp[1] = nums[1];

  for (int i = 2; i < n; i++)
    dp[i] = *max_element(dp.begin(), dp.begin() + i - 1) + nums[i];

  return *max_element(dp.begin(), dp.end());
}
