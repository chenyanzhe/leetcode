#include "SummaryRanges.hpp"

vector<string> SummaryRanges::summaryRanges(vector<int> &nums) {
    vector<string> result;
    int i = 0;

    while (i < nums.size()) {
        int j = i + 1;

        while (j < nums.size() && nums[j] == nums[j - 1] + 1)
            j++;

        if (j == i + 1)
            result.push_back(to_string(nums[i]));
        else
            result.push_back(to_string(nums[i]) + "->" + to_string(nums[j - 1]));

        i = j;
    }

    return result;
}
