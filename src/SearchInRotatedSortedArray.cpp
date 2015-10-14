#include "SearchInRotatedSortedArray.hpp"

int SearchInRotatedSortedArray::search(vector<int>& nums, int target)
{
    int l = 0;
    int h = nums.size() - 1;
    while (l <= h) {
        int m = (l + h) / 2;
        if (nums[m] == target) return m;

        if (nums[l] <= nums[m]) { // elements from l to m are sorted
            if (nums[l] <= target && target < nums[m]) // target in this range
                h = m - 1;
            else // target not in this range
                l = m + 1;
        } else { // elements from m + 1 to h are sorted
            if (nums[m] < target && target <= nums[h]) // target in this range
                l = m + 1;
            else // target not in this range
                h = m - 1;
        }
    }

    // target not found
    return -1;
}