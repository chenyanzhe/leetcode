#include "SplitArrayLargestSum.hpp"

int SplitArrayLargestSum::splitArray(vector<int> &nums, int m) {
    if (nums.empty()) return 0;
    if (nums.size() == 1) return nums[0];

    long long left = nums[0];
    long long right = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        left = max(left, (long long) nums[i]);
        right += nums[i];
    }

    while (left < right) {
        long long mid = left + (right - left) / 2;
        if (canSplit(nums, m, mid)) right = mid;
        else left = mid + 1;
    }

    return (int) right;
}

bool SplitArrayLargestSum::canSplit(vector<int> &nums, int m, long long bucket) {
    long long acc = 0;
    for (int i = 0; i < nums.size(); i++) {
        acc += nums[i];
        if (acc > bucket) {
            m--;
            if (m == 0) return false;
            acc = nums[i];
        }
    }
    return true;
}
