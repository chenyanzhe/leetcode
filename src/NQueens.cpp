#include "NQueens.hpp"

#include <cstdlib>
using namespace std;

vector<vector<string>> NQueens::solveNQueens(int n)
{
  this->n = n;
  vector<int> locs(n + 1, 0);
  vector<vector<string>> result;
  helper(locs, 1, result);
  return result;
}

void NQueens::helper(vector<int>& locs, int r, vector<vector<string>>& result)
{
  if (r == n + 1) {
    vector<string> sol;
    for (int i = 1; i <= n; i++) {
      string line(n, '.');
      line[locs[i] - 1] = 'Q';
      sol.push_back(line);
    }
    result.push_back(sol);
    return;
  }

  for (int i = 1; i <= n; i++) {
    locs[r] = i;
    if (legal(locs, r))
      helper(locs, r + 1, result);
    else
      locs[r] = 0;
  }
}

bool NQueens::legal(vector<int>& locs, int r)
{
  for (int i = 1; i < r; i++)
    if (abs(locs[i] - locs[r]) == abs(i - r) || locs[i] == locs[r])
      return false;
  return true;
}
