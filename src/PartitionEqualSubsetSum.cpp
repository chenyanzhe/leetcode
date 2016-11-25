#include "PartitionEqualSubsetSum.hpp"

#include <numeric>

using namespace std;

bool PartitionEqualSubsetSum::canPartition(vector<int> &nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);

    // if sum is odd, can not be partitioned equally
    if (sum & 0x1) return false;

    int half = sum >> 1;

    vector<bool> dp(half + 1, false);

    dp[0] = true;

    for (auto d : nums) {
        // for every element d in nums, update dp array accordingly
        for (int i = half; i >= d; i--) {
            dp[i] = dp[i] || dp[i - d];
        }
    }

    return dp[half];
}
