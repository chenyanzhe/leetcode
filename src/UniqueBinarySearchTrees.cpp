#include "UniqueBinarySearchTrees.hpp"

#include <vector>
using namespace std;

int UniqueBinarySearchTrees::numTrees(int n)
{
  vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

  for (int i = 1; i <= n + 1; i++)
    dp[i][i] = dp[i][i - 1] = 1;

  for (int l = 2; l <= n; l++) {
    for (int i = 1; i <= n + 1 - l; i++) {
      int j = i + l - 1;

      for (int k = i; k <= j; k++)
        dp[i][j] += dp[i][k - 1] * dp[k + 1][j];
    }
  }

  return dp[1][n];
}
