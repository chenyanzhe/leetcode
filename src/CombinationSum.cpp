#include "CombinationSum.hpp"

#include <algorithm>
using namespace std;

vector<vector<int>> CombinationSum::combinationSum(vector<int>& candidates,
                 int target)
{
  vector<vector<int>> res;
  vector<int> comb;
  sort(candidates.begin(), candidates.end());
  helper(candidates, target, res, comb, 0);
  return res;
}

void CombinationSum::helper(vector<int>& candidates, int target,
                            vector<vector<int>>& res,
                            vector<int>& comb, int begin)
{
  if (!target) {
    res.push_back(comb);
    return;
  }

  for (int i = begin; i != candidates.size() && candidates[i] <= target; i++) {
    comb.push_back(candidates[i]);
    helper(candidates, target - candidates[i], res, comb, i);
    comb.pop_back();
  }
}
