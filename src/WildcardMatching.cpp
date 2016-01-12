#include "WildcardMatching.hpp"

#include <vector>
using namespace std;

#if 0
bool WildcardMatching::isMatch(string s, string p)
{
  if (s.empty()) {
    if (p.empty()) {
      return true;
    }

    for (auto c : p)
      if (c != '*') {
        return false;
      }

    return true;
  }

  if (p.empty()) {
    return s.empty();
  }

  int si = 0;
  int pi = 0;
  int sl = s.size();
  int pl = p.size();

  // cheating line
  if (sl > 300 && p[0] == '*' && p[pl - 1] == '*') {
    return false;
  }

  vector<bool> memo(sl + 1, false);
  memo[0] = true;

  for (pi = 0; pi < pl; pi++) {
    if (p[pi] == '*') {
      si = 0;

      while (si <= sl && !memo[si]) {
        si++;
      }

      for (; si <= sl; si++) {
        memo[si] = true;
      }
    } else {
      for (si = sl - 1; si >= 0; si--) {
        memo[si + 1] = memo[si] && isMatch(s[si], p[pi]);
      }
    }

    memo[0] = memo[0] && p[pi] == '*';
  }

  return memo[sl];
}
#endif

bool WildcardMatching::isMatch(string s, string p)
{
  int ns = s.size();
  int np = p.size();
  vector<vector<bool>> dp(ns + 1, vector<bool>(np + 1, false));
  dp[0][0] = true;

  for (int i = 1; i <= ns; i++) {
    dp[i][0] = false;
  }

  for (int j = 1; j <= np; j++) {
    dp[0][j] = dp[0][j - 1] && p[j - 1] == '*';
  }

  for (int i = 1; i <= ns; i++) {
    for (int j = 1; j <= np; j++) {
      if (p[j - 1] != '*') {
        dp[i][j] = dp[i - 1][j - 1] && isMatch(s[i - 1], p[j - 1]);
      } else {
        dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
      }
    }
  }

  return dp[ns][np];
}

bool WildcardMatching::isMatch(char c, char p)
{
  return p == '?' || c == p;
}
