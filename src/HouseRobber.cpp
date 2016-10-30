#include "HouseRobber.hpp"

int HouseRobber::rob(vector<int> &nums) {
    size_t n = nums.size();

    if (n == 0) return 0;
    if (n == 1) return nums[0];
    if (n == 2) return max(nums[0], nums[1]);

    vector<int> dp(n + 1, 0);
    dp[1] = nums[0];
    dp[2] = max(nums[0], nums[1]);

    for (int i = 3; i <= n; i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);

    return dp[n];
}
