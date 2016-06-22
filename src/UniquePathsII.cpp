#include "UniquePathsII.hpp"

int UniquePathsII::uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
  int m = obstacleGrid.size();

  if (m == 0)
    return 0;

  int n = obstacleGrid[0].size();

  if (n == 0)
    return 0;

  vector<int> dp(n, 1);
  dp[0] = (obstacleGrid[0][0] == 1) ? 0 : 1;

  for (int j = 1; j < n; j++) {
    if (dp[j - 1] == 0 || obstacleGrid[0][j] == 1)
      dp[j] = 0;
    else
      dp[j] = 1;
  }

  for (int i = 1; i < m; i++) {
    if (dp[0] == 0 || obstacleGrid[i][0] == 1)
      dp[0] = 0;
    else
      dp[0] = 1;

    for (int j = 1; j < n; j++) {
      int up = 0;

      if (dp[j] != 0 && obstacleGrid[i][j] != 1)
        up = dp[j];

      int left = 0;

      if (dp[j - 1] != 0 && obstacleGrid[i][j] != 1)
        left = dp[j - 1];

      dp[j] = up + left;
    }
  }

  return dp[n - 1];
}

