#include "WiggleSubsequence.hpp"

int WiggleSubsequence::wiggleMaxLength(vector<int> &nums) {
    return wiggleMaxLength_Linear(nums);
}

int WiggleSubsequence::wiggleMaxLength_DynamicProgramming(vector<int> &nums) {
    if (nums.empty()) return 0;

    size_t n = nums.size();

    vector<int> increase(n, 1);
    vector<int> decrease(n, 1);

    int max_increase = 1;
    int max_decrease = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) increase[i] = max(increase[i], decrease[j] + 1);
            if (nums[j] > nums[i]) decrease[i] = max(decrease[i], increase[j] + 1);
        }
        max_increase = max(max_increase, increase[i]);
        max_decrease = max(max_decrease, decrease[i]);
    }

    return max(max_increase, max_decrease);
}

int WiggleSubsequence::wiggleMaxLength_Linear(vector<int> &nums) {
    if (nums.empty()) return 0;

    int max_increase = 1;
    int max_decrease = 1;

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i - 1] < nums[i]) max_increase = max_decrease + 1;
        if (nums[i - 1] > nums[i]) max_decrease = max_increase + 1;
    }

    return max(max_increase, max_decrease);
}
