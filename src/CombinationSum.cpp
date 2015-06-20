#include "CombinationSum.hpp"

#include <algorithm>
#include <iostream>
using namespace std;

vector<vector<int>> CombinationSum::combinationSum(vector<int>& candidates, int target)
{
  vector<vector<int>> ret;
  vector<int> result;
  sort(candidates.begin(), candidates.end());
  helper(candidates, target, result, 0, ret);
  return ret;
}

void CombinationSum::helper(vector<int>& candidates, int target, vector<int>& result, int l, vector<vector<int>>& global)
{
  if (l >= candidates.size() || candidates[l] > target)
    return;

  for (int i = l; i < candidates.size(); i++) {
    int c = candidates[i];
    if (c == target) {
      global.push_back(result);
      global[global.size() - 1].push_back(c);
    } else {
      result.push_back(c);
      helper(candidates, target - c, result, i, global);
      result.erase(find(result.begin(), result.end(), c));
    }
  }
}
