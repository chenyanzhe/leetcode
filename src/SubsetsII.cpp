#include "SubsetsII.hpp"

#include <algorithm>

using namespace std;

vector<vector<int>> SubsetsII::subsetsWithDup(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> global;
    vector<int> local;
    vector<bool> visited(nums.size(), false);
    backtrack(nums, 0, visited, local, global);
    return global;
}

void SubsetsII::backtrack(vector<int> &nums, int begin, vector<bool> &visited, vector<int> &local,
                          vector<vector<int>> &global) {
    if (begin == nums.size()) {
        global.push_back(local);
        return;
    }

    if (begin == 0 || nums[begin - 1] != nums[begin] || visited[begin - 1]) {
        visited[begin] = true;
        local.push_back(nums[begin]);
        backtrack(nums, begin + 1, visited, local, global);
        local.pop_back();
        visited[begin] = false;
    }
    backtrack(nums, begin + 1, visited, local, global);
}
