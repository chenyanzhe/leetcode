#include "LargestDivisibleSubset.hpp"

#include <algorithm>

using namespace std;

vector<int> LargestDivisibleSubset::largestDivisibleSubset(vector<int> &nums) {
    vector<int> ret;

    if (nums.empty()) return ret;

    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<int> dp(n, 1), pre(n, -1);
    int max_idx = 0, max_val = 1;

    for (int i = 0; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                pre[i] = j;
            }
        }

        if (dp[i] > max_val) {
            max_val = dp[i];
            max_idx = i;
        }
    }

    int k = max_idx;

    while (k != -1) {
        ret.push_back(nums[k]);
        k = pre[k];
    }

    return ret;
}
