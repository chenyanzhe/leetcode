#include "CombinationSumIII.hpp"

vector<vector<int>> CombinationSumIII::combinationSum3(int k, int n) {
    vector<vector<int>> result;
    vector<int> cur;
    backtrack(k, n, 1, 0, cur, result);
    return result;
}

void
CombinationSumIII::backtrack(int k, int target, int depth, int sum, vector<int> &cur, vector<vector<int>> &result) {
    if (k == 0 && sum == target) {
        result.push_back(cur);
        return;
    }

    if (k == 0 || sum > target) return;

    for (int i = depth; i <= 9; i++) {
        cur.push_back(i);

        backtrack(k - 1, target, i + 1, sum + i, cur, result);

        cur.pop_back();
    }
}
