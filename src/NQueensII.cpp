#include "NQueensII.hpp"

#include <cstdlib>
using namespace std;

int NQueensII::totalNQueens(int n)
{
  this->n = n;
  vector<int> locs(n + 1, 0);
  int result = 0;

  helper(locs, 1, result);

  return result;
}

void NQueensII::helper(vector<int>& locs, int r, int& result)
{
  if (r == n + 1) {
    result++;
    return;
  }

  for (int i = 1; i <= n; i++) {
    locs[r] = i;
    if (valid(locs, r))
      helper(locs, r + 1, result);
    else
      locs[r] = 0;
  }
}

bool NQueensII::valid(vector<int>& locs, int r)
{
  for (int i = 1; i < r; i++) {
    if (abs(locs[i] - locs[r]) == abs(i - r) || locs[i] == locs[r])
      return false;
  }
  return true;
}
