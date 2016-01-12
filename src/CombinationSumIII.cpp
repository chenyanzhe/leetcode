#include "CombinationSumIII.hpp"

vector<vector<int>> CombinationSumIII::combinationSum3(int k, int n)
{
  vector<vector<int>> result;
  vector<int> now;
  bt(k, n, 1, now, result);
  return result;
}

void CombinationSumIII::bt(int k, int n, int i, vector<int>& now,
                           vector<vector<int>>& result)
{
  if (k == 0 && n == 0) {
    result.push_back(now);
  }

  if (n < i || k == 0 || i > 9) {
    return;
  }

  bt(k, n, i + 1, now, result);
  now.push_back(i);
  bt(k - 1, n - i, i + 1, now, result);
  now.pop_back();
}
