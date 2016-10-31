#include "LongestIncreasingSubsequence.hpp"

int LongestIncreasingSubsequence::lengthOfLIS(vector<int> &nums) {
    return lengthOfLIS_BinarySearch(nums);
}

int LongestIncreasingSubsequence::lengthOfLIS_DynamicProgramming(vector<int> &nums) {
    if (nums.empty()) return 0;

    size_t n = nums.size();
    vector<int> dp(n, 1);
    int ret = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        ret = max(ret, dp[i]);
    }

    return ret;
}

int LongestIncreasingSubsequence::lengthOfLIS_BinarySearch(vector<int> &nums) {
    if (nums.empty()) return 0;

    size_t n = nums.size();
    int end = 0;
    vector<int> tails(n, 0);

    for (int i = 0; i < n; i++) {
        int idx = binarySearch(tails, end, nums[i]);
        tails[idx] = nums[i];
        if (idx == end) end++;
    }

    return end;
}

int LongestIncreasingSubsequence::binarySearch(vector<int> &tails, int end, int target) {
    if (end == 0) return end;

    int l = 0, r = end - 1;
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (tails[m] < target)
            l = m;
        else
            r = m;
    }

    if (tails[l] >= target)
        return l;

    if (tails[r] >= target)
        return r;
    else
        return r + 1;
}
