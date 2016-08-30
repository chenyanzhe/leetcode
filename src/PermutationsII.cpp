#include "PermutationsII.hpp"

#include <algorithm>

using namespace std;

vector<vector<int>> PermutationsII::permuteUnique(vector<int> &nums) {
    vector<vector<int>> result;
    vector<int> cur;
    vector<bool> used(nums.size(), false);

    sort(nums.begin(), nums.end());
    backtrack(nums, 0, used, cur, result);

    return result;
}

void PermutationsII::backtrack(vector<int> &nums, int depth, vector<bool> &used, vector<int> &cur,
                               vector<vector<int>> &result) {
    if (depth >= nums.size()) {
        result.push_back(cur);
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (used[i] || (i > 0 && nums[i - 1] == nums[i] && !used[i - 1]))
            continue;

        used[i] = true;
        cur.push_back(nums[i]);

        backtrack(nums, depth + 1, used, cur, result);

        used[i] = false;
        cur.pop_back();
    }
}
