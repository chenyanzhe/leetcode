#include "WildcardMatching.hpp"

#include <vector>
using namespace std;

bool WildcardMatching::isMatch(string s, string p)
{
  return isMatch_Greedy(s, p);
}

bool WildcardMatching::isMatch_DynamicProgramming(string s, string p)
{
  int m = s.size();
  int n = p.size();
  vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
  dp[0][0] = true;

  for (int i = 1; i <= m; i++) {
    dp[i][0] = false;
  }

  for (int j = 1; j <= n; j++) {
    dp[0][j] = dp[0][j - 1] && p[j - 1] == '*';
  }

  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (p[j - 1] != '*') {
        dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '?');
      } else {
        dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
      }
    }
  }

  return dp[m][n];
}

bool WildcardMatching::isMatch_Greedy(string s, string p)
{
  int m = s.size(), n = p.size();
  int i = 0, j = 0, asterisk = -1, match;

  while (i < m) {
    if (j < n && p[j] == '*') {
      match = i;
      asterisk = j++;
    } else if (j < n && (s[i] == p[j] || p[j] == '?')) {
      i++;
      j++;
    } else if (asterisk >= 0) {
      i = ++match;
      j = asterisk + 1;
    } else {
      return false;
    }
  }

  while (j < n && p[j] == '*') {
    j++;
  }

  return j == n;
}
