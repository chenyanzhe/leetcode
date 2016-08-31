#include "CombinationSum.hpp"

#include <algorithm>

using namespace std;

vector<vector<int>> CombinationSum::combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> result;
    vector<int> cur;
    backtrack(candidates, target, 0, 0, cur, result);
    return result;
}

void CombinationSum::backtrack(vector<int> &candidates, int target, int depth, int sum, vector<int> &cur,
                               vector<vector<int>> &result) {
    if (sum == target) {
        result.push_back(cur);
        return;
    }

    if (sum > target)
        return;

    for (int i = depth; i < candidates.size(); i++) {
        cur.push_back(candidates[i]);
        backtrack(candidates, target, i, sum + candidates[i], cur, result);
        cur.pop_back();
    }
}
