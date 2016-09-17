#include "SearchForARange.hpp"

vector<int> SearchForARange::searchRange(vector<int> &nums, int target) {
    vector<int> ret{-1, -1};

    if (nums.empty()) return ret;

    int l = 0;
    int r = nums.size() - 1;
    while (l < r) {
        int m = l + (r - l) / 2;
        if (nums[m] == target) {
            r = m;
        } else if (nums[m] < target) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    if (nums[r] == target)
        ret[0] = r;
    else
        return ret;

    l = r, r = nums.size() - 1;
    while (l < r) {
        int m = l + (r - l + 1) / 2;
        if (nums[m] == target) {
            l = m;
        } else if (nums[m] < target) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    if (nums[l] == target)
        ret[1] = l;

    return ret;
}
