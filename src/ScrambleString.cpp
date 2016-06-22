#include "ScrambleString.hpp"

#include <vector>
using namespace std;

bool ScrambleString::isScramble(string s1, string s2)
{
  if (s1.size() != s2.size())
    return false;

  if (s1 == s2)
    return true;

  int n = s1.size();
  vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(n,
                                  false)));

  // dp[i][j][k]: s1[i:i+k] v.s. s2[j:j+k]
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      dp[i][j][0] = (s1[i] == s2[j]);

  for (int k = 1; k < n; k++) {
    for (int i = 0; i < n - k; i++) {
      for (int j = 0; j < n - k; j++) {
        for (int p = 0; p < k; p++) {
          // s1[i:i+p] + s1[i+p+1:i+k] v.s. s2[j:j+p] + s2[j+p+1:j+k]
          // s1[i:i+p] + s1[i+p+1:i+k] v.s. s2[j:j+k-p-1] + s2[j+k-p:j+k]
          if ((dp[i][j][p] && dp[i + p + 1][j + p + 1][k - p - 1]) ||
              (dp[i][j + k - p][p] && dp[i + p + 1][j][k - p - 1]))
            dp[i][j][k] = true;
        }
      }
    }
  }

  return dp[0][0][n - 1];
}
