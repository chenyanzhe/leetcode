#include "MissingRanges.hpp"

vector<string> MissingRanges::findMissingRanges(vector<int> &nums, int lower, int upper) {
    vector<string> ret;
    if (lower > upper) return ret;

    int left = lower;

    for (int i = 0; i < nums.size(); i++) {
        if (left < nums[i]) {
            addRange(left, nums[i] - 1, ret);
        }

        if (nums[i] == INT_MAX) return ret;

        left = nums[i] + 1;
    }

    if (left <= upper)
        addRange(left, upper, ret);

    return ret;
}

void MissingRanges::addRange(int left, int right, vector<string> &res) {
    if (left == right)
        res.push_back(to_string(left));
    else
        res.push_back(to_string(left) + "->" + to_string(right));
}