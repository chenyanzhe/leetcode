#include "Triangle.hpp"

int Triangle::minimumTotal(vector<vector<int>>& triangle)
{
  int m = triangle.size();

  if (m == 0) {
    return 0;
  }

  vector<vector<int>> dp(m, vector<int>(m, 0));
  dp[0][0] = triangle[0][0];

  for (int i = 1; i < m; i++) {
    dp[i][0] = dp[i - 1][0] + triangle[i][0];

    for (int j = 1; j < i; j++)
      dp[i][j] = ((dp[i - 1][j] < dp[i - 1][j - 1]) ? dp[i - 1][j] : dp[i - 1][j -
                  1])
                 + triangle[i][j];

    dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
  }

  int ret = dp[m - 1][0];

  for (int j = 1; j < m; j++) {
    ret = (ret > dp[m - 1][j]) ? dp[m - 1][j] : ret;
  }

  return ret;
}
