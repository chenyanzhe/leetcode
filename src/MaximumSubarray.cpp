#include "MaximumSubarray.hpp"

int MaximumSubarray::maxSubArray(vector<int> &nums) {
    if (nums.empty()) return 0;

    int mx, lmx, rmx, sum;
    maxSubArray_DivideAndConquer(nums, 0, nums.size() - 1, mx, lmx, rmx, sum);
    return mx;
}

int MaximumSubarray::maxSubArray_DynamicProgramming(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = nums[0];

    for (int i = 1; i < n; i++)
        dp[i] = max(dp[i - 1] + nums[i], nums[i]);

    int ret = dp[0];

    for (int i = 1; i < n; i++)
        ret = max(ret, dp[i]);

    return ret;
}

//  mx: largest sum of this subarray
// lmx: largest sum starting from the left most element
// rmx: largest sum ending with the right most element
// sum: the sum of the total subarray

void
MaximumSubarray::maxSubArray_DivideAndConquer(vector<int> &nums, int l, int r, int &mx, int &lmx, int &rmx, int &sum) {
    if (l == r)
        mx = lmx = rmx = sum = nums[l];
    else {
        int m = (l + r) / 2;

        int mx1, lmx1, rmx1, sum1;
        int mx2, lmx2, rmx2, sum2;
        maxSubArray_DivideAndConquer(nums, l, m, mx1, lmx1, rmx1, sum1);
        maxSubArray_DivideAndConquer(nums, m + 1, r, mx2, lmx2, rmx2, sum2);

        lmx = max(lmx1, sum1 + lmx2);
        rmx = max(rmx2, rmx1 + sum2);
        sum = sum1 + sum2;
        mx = max(max(mx1, mx2), rmx1 + lmx2);
    }
}

