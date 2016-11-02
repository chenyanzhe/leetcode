#include "PartitionEqualSubsetSum.hpp"

bool PartitionEqualSubsetSum::canPartition(vector<int> &nums) {
    int total = 0;
    for (auto d : nums)
        total += d;

    if (total & 0x1) return false;

    vector<bool> dp(total / 2 + 1, 0);

    dp[0] = true;

    for (auto d : nums) {
        for (int i = total / 2; i >= d; i--) {
            dp[i] = dp[i] || dp[i - d];
        }
    }

    return dp[total / 2];
}
