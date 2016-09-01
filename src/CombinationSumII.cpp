#include "CombinationSumII.hpp"

#include <algorithm>

using namespace std;

vector<vector<int>> CombinationSumII::combinationSum2(vector<int> &candidates, int target) {
    vector<vector<int>> result;
    vector<int> cur;

    sort(candidates.begin(), candidates.end());
    backtrack(candidates, target, 0, 0, cur, result);

    return result;
}

void CombinationSumII::backtrack(vector<int> &candidates, int target, int depth, int sum, vector<int> &cur,
                                 vector<vector<int>> &result) {
    if (sum == target) {
        result.push_back(cur);
        return;
    }

    if (sum > target)
        return;

    for (int i = depth; i < candidates.size(); i++) {
        if (i > depth && candidates[i - 1] == candidates[i])
            continue;

        cur.push_back(candidates[i]);

        backtrack(candidates, target, i + 1, sum + candidates[i], cur, result);

        cur.pop_back();
    }
}
