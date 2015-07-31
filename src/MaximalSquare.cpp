#include "MaximalSquare.hpp"

int MaximalSquare::maximalSquare(vector<vector<char>>& matrix)
{
  int m = matrix.size();
  if (m == 0) return 0;
  int n = matrix[0].size();
  if (n == 0) return 0;

  vector<vector<int>> dp(m, vector<int>(n, 0));

  for (int i = 0; i < m; i++)
    dp[i][0] = (matrix[i][0] == '1') ? 1 : 0;
  for (int j = 0; j < n; j++)
    dp[0][j] = (matrix[0][j] == '1') ? 1 : 0;

  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      int uw = dp[i-1][j-1];
      int w;
      for (w = 0; w <= uw; w++)
        if (matrix[i][j-w] == '0' || matrix[i-w][j] == '0')
          break;
      dp[i][j] = w;
    }
  }

  int ret = 0;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      if (dp[i][j] > ret)
        ret = dp[i][j];

  return ret * ret;
}
