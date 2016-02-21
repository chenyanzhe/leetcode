#include "UniquePaths.hpp"

#include <vector>
#include <algorithm>
using namespace std;

int UniquePaths::uniquePaths(int m, int n)
{
  return uniquePaths_Optimized(m, n);
}

int UniquePaths::uniquePaths_Raw(int m, int n)
{
  vector<vector<int>> dp(m, vector<int>(n, 1));

  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }
  }

  return dp[m - 1][n - 1];
}

int UniquePaths::uniquePaths_Optimized(int m, int n)
{
  if (m > n) {
    return uniquePaths_Optimized(n, m);
  }

  vector<int> pre(m, 1);
  vector<int> cur(m, 1);

  for (int j = 1; j < n; j++) {
    for (int i = 1; i < m; i++) {
      cur[i] = cur[i - 1] + pre[i];
    }

    swap(pre, cur);
  }

  return pre[m - 1];
}
