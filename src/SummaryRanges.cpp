#include "SummaryRanges.hpp"

vector<string> SummaryRanges::summaryRanges(vector<int> &nums) {
    vector<string> ret;
    if (nums.empty()) return ret;

    int start = nums[0];
    int end = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] - 1 == end) {
            end = nums[i];
        } else {
            addRange(start, end, ret);
            start = nums[i];
            end = nums[i];
        }
    }
    addRange(start, end, ret);

    return ret;
}

void SummaryRanges::addRange(int start, int end, vector<string> &res) {
    if (start == end)
        res.push_back(to_string(start));
    else
        res.push_back(to_string(start) + "->" + to_string(end));
}
