#include "MinimumPathSum.hpp"

#include <algorithm>
using namespace std;

int MinimumPathSum::minPathSum(vector<vector<int>>& grid)
{
  return minPathSum_Optimized(grid);
}

int MinimumPathSum::minPathSum_Raw(vector<vector<int>>& grid)
{
  int m = grid.size();
  int n = grid[0].size();
  vector<vector<int>> dp(m, vector<int>(n, 0));
  dp[0][0] = grid[0][0];

  for (int i = 1; i < m; i++) {
    dp[i][0] = dp[i - 1][0] + grid[i][0];
  }

  for (int j = 1; j < n; j++) {
    dp[0][j] = dp[0][j - 1] + grid[0][j];
  }

  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
    }
  }

  return dp[m - 1][n - 1];
}

int MinimumPathSum::minPathSum_Optimized(vector<vector<int>>& grid)
{
  int m = grid.size();
  int n = grid[0].size();
  vector<int> pre(m, 0);
  vector<int> cur(m, 0);
  pre[0] = grid[0][0];

  for (int i = 1; i < m; i++) {
    pre[i] = pre[i - 1] + grid[i][0];
  }

  for (int j = 1; j < n; j++) {
    cur[0] = pre[0] + grid[0][j];

    for (int i = 1; i < m; i++) {
      cur[i] = min(pre[i], cur[i - 1]) + grid[i][j];
    }

    swap(pre, cur);
  }

  return pre[m - 1];
}