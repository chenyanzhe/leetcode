#include "Combinations.hpp"

vector<vector<int>> Combinations::combine(int n, int k)
{
  vector<vector<int>> res;
  vector<int> temp(0, k);
  helper(res, temp, 0, n, k);
  return res;
}

void Combinations::helper(vector<vector<int>>& res, vector<int>& temp,
                          int start, int n, int k)
{
  if (temp.size() == k) {
    res.push_back(temp);
    return;
  }

  for(int i = start; i < n; i++) {
    temp.push_back(i + 1);
    helper(res, temp, i + 1, n, k);
    temp.pop_back();
  }
}
