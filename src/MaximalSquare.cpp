#include "MaximalSquare.hpp"

#include <algorithm>
using namespace std;

int MaximalSquare::maximalSquare(vector<vector<char>>& matrix)
{
  int n = matrix.size();

  if (n == 0)
    return 0;

  int m = matrix[0].size();

  if (m == 0)
    return 0;

  vector<vector<int>> dp(n, vector<int>(m, 0));
  int maxr = 0;

  for (int i = 0; i < n; i++) {
    dp[i][0] = (matrix[i][0] == '1') ? 1 : 0;
    maxr = max(dp[i][0], maxr);
  }

  for (int j = 0; j < m; j++) {
    dp[0][j] = (matrix[0][j] == '1') ? 1 : 0;
    maxr = max(dp[0][j], maxr);
  }

  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      if (matrix[i][j] == '0')
        dp[i][j] = 0;
      else {
        // r = min{ dp[i-1][j], dp[i][j-1], dp[i-1][j-1] }
        int r = min(dp[i - 1][j], dp[i][j - 1]);
        r = min(dp[i - 1][j - 1], r);
        dp[i][j] = r + 1;
      }

      maxr = max(dp[i][j], maxr);
    }
  }

  return maxr * maxr;
}
