#include "SearchForARange.hpp"

vector<int> SearchForARange::searchRange(vector<int> &nums, int target) {
    vector<int> ret{-1, -1};

    if (nums.empty()) return ret;

    int len = nums.size();
    int i = 0;
    int j = len - 1;

    while (i < j - 1) {
        int m = i + (j - i) / 2;
        if (target == nums[m]) {
            j = m;
        } else if (target > nums[m]) {
            i = m;
        } else {
            j = m;
        }
    }

    if (nums[i] == target) {
        ret[0] = i;
    } else if (nums[j] == target) {
        ret[0] = j;
    } else {
        return ret;
    }

    i = 0;
    j = len - 1;

    while (i < j - 1) {
        int m = i + (j - i) / 2;
        if (target == nums[m]) {
            i = m;
        } else if (target > nums[m]) {
            i = m;
        } else {
            j = m;
        }
    }

    if (nums[j] == target) {
        ret[1] = j;
    } else if (nums[i] == target) {
        ret[1] = i;
    } else {
        return ret;
    }

    return ret;
}
