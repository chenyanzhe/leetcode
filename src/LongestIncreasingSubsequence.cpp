#include "LongestIncreasingSubsequence.hpp"

#include <set>

using namespace std;

int LongestIncreasingSubsequence::lengthOfLIS(vector<int> &nums) {
    int n = nums.size();
    set<int> s(nums.begin(), nums.end());
    vector<int> snums;
    snums.assign(s.begin(), s.end());
    int m = snums.size();
    vector<int> dp(m + 1, 0);

    for (int i = 1; i <= n; i++) {
        int newv = dp[0];

        for (int j = 1; j <= m; j++) {
            int oldv = dp[j];

            if (nums[i - 1] == snums[j - 1])
                dp[j] = newv + 1;
            else
                dp[j] = max(dp[j], dp[j - 1]);

            newv = oldv;
        }
    }

    return dp[m];
}
