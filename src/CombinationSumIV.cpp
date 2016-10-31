#include "CombinationSumIV.hpp"

int CombinationSumIV::combinationSum4(vector<int> &nums, int target) {
    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= target; i++)
        for (auto d : nums)
            if (d <= i) dp[i] += dp[i - d];

    return dp[target];
}
