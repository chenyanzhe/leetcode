#include "FindMinimumInRotatedSortedArrayII.hpp"

int FindMinimumInRotatedSortedArrayII::findMin(vector<int> &nums) {
    int l = 0, r = nums.size() - 1;

    while (l < r && nums[l] >= nums[r]) {
        if (nums[l] == nums[r])
            r--;
        else {
            int m = l + (r - l) / 2;
            if (nums[l] <= nums[m])
                l = m + 1;
            else
                r = m;
        }
    }

    return nums[l];
}
