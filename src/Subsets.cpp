#include "Subsets.hpp"

vector<vector<int>> Subsets::subsets(vector<int> &nums) {
    vector<vector<int>> global;
    vector<int> local;
    backtrack(nums, 0, local, global);
    return global;
}

void Subsets::backtrack(vector<int> &nums, int begin, vector<int> &local, vector<vector<int>> &global) {
    if (begin == nums.size()) {
        global.push_back(local);
        return;
    }

    local.push_back(nums[begin]);
    backtrack(nums, begin + 1, local, global);
    local.pop_back();
    backtrack(nums, begin + 1, local, global);
}
