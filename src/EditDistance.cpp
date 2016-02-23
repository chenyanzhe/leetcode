#include "EditDistance.hpp"

#include <vector>
#include <algorithm>
using namespace std;

int EditDistance::minDistance(string word1, string word2)
{
  return minDistance_Optimized(word1, word2);
}

int EditDistance::minDistance_Raw(string word1, string word2)
{
  int m = word1.length(), n = word2.length();
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

  for (int i = 1; i <= m; i++) {
    dp[i][0] = i;
  }

  for (int j = 1; j <= n; j++) {
    dp[0][j] = j;
  }

  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (word1[i - 1] == word2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1];
      } else {
        dp[i][j] = min(dp[i - 1][j - 1] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j] + 1));
      }
    }
  }

  return dp[m][n];
}

int EditDistance::minDistance_Optimized(string word1, string word2)
{
  int m = word1.length(), n = word2.length();
  vector<int> pre(m + 1, 0);
  vector<int> cur(m + 1, 0);

  for (int i = 1; i <= m; i++) {
    pre[i] = i;
  }

  for (int j = 1; j <= n; j++) {
    cur[0] = j;

    for (int i = 1; i <= m; i++) {
      if (word1[i - 1] == word2[j - 1]) {
        cur[i] = pre[i - 1];
      } else {
        cur[i] = min(pre[i - 1] + 1, min(pre[i] + 1, cur[i - 1] + 1));
      }
    }

    swap(pre, cur);
  }

  return pre[m];
}