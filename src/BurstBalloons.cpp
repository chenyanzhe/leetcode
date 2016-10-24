#include "BurstBalloons.hpp"

int BurstBalloons::maxCoins(vector<int> &nums) {
    if (nums.empty()) return 0;

    int n = nums.size();

    vector<int> exnums(n + 2, 0);

    exnums[0] = exnums[n + 1] = 1;
    for (int i = 1; i <= n; i++)
        exnums[i] = nums[i - 1];

    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    for (int k = 2; k < n + 2; k++) {
        for (int l = 0; l + k < n + 2; l++) {
            int r = l + k;
            for (int m = l + 1; m < r; m++)
                dp[l][r] = max(dp[l][r], exnums[l] * exnums[m] * exnums[r] + dp[l][m] + dp[m][r]);
        }
    }

    return dp[0][n + 1];
}
