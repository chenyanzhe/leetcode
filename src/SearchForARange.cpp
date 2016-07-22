#include "SearchForARange.hpp"

vector<int> SearchForARange::searchRange(vector<int> &nums, int target) {
    vector<int> ret{-1, -1};
    int sz = nums.size();

    if (sz == 0)
        return ret;

    int i = 0;
    int j = sz - 1;

    while (i < j) {
        int mid = (i + j) / 2;

        if (nums[mid] < target)
            i = mid + 1;
        else
            j = mid;
    }

    if (nums[i] == target)
        ret[0] = i;
    else
        return ret;

    j = sz - 1;

    while (i < j) {
        int mid = (i + j) / 2 + 1;

        if (nums[mid] > target)
            j = mid - 1;
        else
            i = mid;
    }

    if (nums[i] == target)
        ret[1] = i;

    return ret;
}
