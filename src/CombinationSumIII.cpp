#include "CombinationSumIII.hpp"

vector<vector<int>> CombinationSumIII::combinationSum3(int k, int n)
{
  vector<vector<int>> res;
  vector<int> comb;
  helper(n, res, comb, 1, k);
  return res;
}

void CombinationSumIII::helper(int target, vector<vector<int>>& res,
                               vector<int>& comb, int begin, int k)
{
  if (!target && !k) {
    res.push_back(comb);
    return;
  } else if (!k)
    return;

  for (int i = begin; i <= 9 && i <= target; i++) {
    comb.push_back(i);
    helper(target - i, res, comb, i + 1, k - 1);
    comb.pop_back();
  }
}
