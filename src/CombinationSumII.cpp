#include "CombinationSumII.hpp"

#include <algorithm>
using namespace std;

vector<vector<int>> CombinationSumII::combinationSum2(vector<int>& candidates, int target)
{
  vector<vector<int>> ret;
  if (candidates.empty()) return ret;

  sort(candidates.begin(), candidates.end());
  vector<int> local;
  helper(candidates, target, 0, local, ret);
  return ret;
}

void CombinationSumII::helper(vector<int>& candidates, int target, int level, vector<int>& local, vector<vector<int>>& global)
{
  if (level >= candidates.size() || candidates[level] > target)
    return;

  for (int i = level; i < candidates.size(); i++) {
    int c = candidates[i];
    if (c == target) {
      global.push_back(local);
      global[global.size() - 1].push_back(candidates[i]);
      return;
    } else {
      local.push_back(c);
      helper(candidates, target - c, i + 1, local, global);
      local.erase(find(local.begin(), local.end(), c));
      while (i + 1 < candidates.size() && c == candidates[i + 1])
        i++;
    }
  }
}
