#include "CombinationSumII.hpp"

using namespace std;

vector<vector<int>> CombinationSumII::combinationSum2(vector<int> &candidates,
                                                      int target) {
    vector<vector<int>> res;
    vector<int> comb;
    sort(candidates.begin(), candidates.end());
    helper(candidates, target, res, comb, 0);
    return res;
}

void CombinationSumII::helper(vector<int> &candidates, int target,
                              vector<vector<int>> &res,
                              vector<int> &comb, int begin) {
    if (!target) {
        res.push_back(comb);
        return;
    }

    for (int i = begin; i != candidates.size() && candidates[i] <= target; i++) {
        if (i == begin || candidates[i] != candidates[i - 1]) {
            comb.push_back(candidates[i]);
            helper(candidates, target - candidates[i], res, comb, i + 1);
            comb.pop_back();
        }
    }
}
