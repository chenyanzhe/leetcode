#include "Permutations.hpp"

vector<vector<int>> Permutations::permute(vector<int> &nums) {
    vector<vector<int>> global;
    vector<int> local;
    vector<bool> visited(nums.size(), false);
    backtrack(nums, 0, visited, local, global);
    return global;
}

void Permutations::backtrack(vector<int> &nums, int begin, vector<bool> &visited, vector<int> &local,
                             vector<vector<int>> &global) {
    if (begin == nums.size()) {
        global.push_back(local);
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            local.push_back(nums[i]);
            backtrack(nums, begin + 1, visited, local, global);
            local.pop_back();
            visited[i] = false;
        }
    }
}