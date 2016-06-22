#include "MinimumPathSum.hpp"

#include <climits>
#include <algorithm>
using namespace std;

int MinimumPathSum::minPathSum(vector<vector<int>>& grid)
{
  int m = grid.size();

  if (m == 0)
    return 0;

  int n = grid[0].size();

  if (n == 0)
    return 0;

  vector<int> dp(n, INT_MAX);
  dp[0] = grid[0][0];

  for (int j = 1; j < n; j++)
    dp[j] = dp[j - 1] + grid[0][j];

  for (int i = 1; i < m; i++) {
    dp[0] += grid[i][0];

    for (int j = 1; j < n; j++)
      dp[j] = min(dp[j - 1], dp[j]) + grid[i][j];
  }

  return dp[n - 1];
}

