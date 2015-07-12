#include "NQueens.hpp"

#include <cstdlib>
#include <iostream>
using namespace std;

vector<vector<string>> NQueens::solveNQueens(int n)
{
  vector<int> locs(n + 1, 0);
  helper(n, locs, 1);
}

void NQueens::helper(int n, vector<int>& locs, int r)
{
  if (r == n + 1) {
    cout << "One solution found" << endl;
    return;
  }

  for (int i = 1; i <= n; i++) {
    locs[r] = i;
    if (legal(n, locs, r))
      helper(n, locs, r + 1);
    else
      locs[r] = 0;
  }
}

bool NQueens::legal(int n, vector<int>& locs, int r)
{
  for (int i = 1; i < r; i++) {
    if (abs(locs[i] - locs[r]) == abs(i - r) || locs[i] == locs[r])
      return false;
  }
  return true;
}
