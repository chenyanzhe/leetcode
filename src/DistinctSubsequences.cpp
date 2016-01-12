#include "DistinctSubsequences.hpp"

#include <vector>
using namespace std;

int DistinctSubsequences::numDistinct(string s, string t)
{
  // match `t` to subsequence of `s`
  int tlen = t.size();
  int slen = s.size();

  if (tlen == 0) {
    return 1;
  }

  if (slen == 0) {
    return (tlen == 0) ? 1 : 0;
  }

  vector<vector<int>> dp(tlen + 1, vector<int>(slen + 1, 0));

  for (int j = 0; j <= slen; j++) {
    dp[0][j] = 1;
  }

  for (int i = 1; i <= tlen; i++) {
    for (int j = 1; j <= slen; j++) {
      dp[i][j] = dp[i][j - 1];

      if (t[i - 1] == s[j - 1]) {
        dp[i][j] += dp[i - 1][j - 1];
      }
    }
  }

  return dp[tlen][slen];
}
