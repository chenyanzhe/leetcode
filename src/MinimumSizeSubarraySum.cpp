#include "MinimumSizeSubarraySum.hpp"

int MinimumSizeSubarraySum::minSubArrayLen(int s, vector<int> &nums) {
    // return minSubArrayLen_Linear(s, nums);
    return minSubArrayLen_BinarySearch(s, nums);
}

int MinimumSizeSubarraySum::minSubArrayLen_Linear(int s, vector<int> &nums) {
    if (nums.empty()) return 0;

    int n = nums.size();
    int l = 0, r = 0, sum = 0, ret = n + 1;
    while (r < n) {
        while (r < n && sum < s) sum += nums[r++];
        while (sum >= s) {
            ret = min(ret, r - l);
            sum -= nums[l++];
        }
    }

    return ret == n + 1 ? 0 : ret;
}

int MinimumSizeSubarraySum::minSubArrayLen_BinarySearch(int s, vector<int> &nums) {
    if (nums.empty()) return 0;

    int n = nums.size(), ret = n + 1;
    vector<int> sums(n + 1, 0);

    for (int i = 1; i <= n; i++)
        sums[i] = sums[i - 1] + nums[i - 1];

    for (int i = 0; i <= n; i++) {
        int r = searchRight(i + 1, n, sums[i] + s, sums);
        if (r == n + 1) break;
        ret = min(ret, r - i);
    }

    return ret == n + 1 ? 0 : ret;
}

int MinimumSizeSubarraySum::searchRight(int l, int r, int target, vector<int> &sums) {
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (sums[m] >= target)
            r = m;
        else
            l = m;
    }

    if (sums[l] >= target)
        return l;
    if (sums[r] >= target)
        return r;
    return sums.size();
}
