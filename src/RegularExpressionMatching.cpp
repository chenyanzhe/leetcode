#include "RegularExpressionMatching.hpp"

#if 0
// Recursion
bool RegularExpressionMatching::isMatch(string s, string p)
{
  if (p.empty()) {
    return s.empty();
  }

  if (p.size() > 1 && '*' == p[1]) {
    // x* matches empty string or at least one character: x* -> xx*
    return isMatch(s, p.substr(2)) ||
           !s.empty() && (s[0] == p[0] || '.' == p[0]) &&
           isMatch(s.substr(1), p);
  } else {
    return !s.empty() && (s[0] == p[0] || '.' == p[0]) &&
           isMatch(s.substr(1), p.substr(1));
  }
}
#endif

// Dynamic Programming

#include <vector>
using namespace std;

bool RegularExpressionMatching::isMatch(string s, string p)
{
  int sl = s.size();
  int pl = p.size();
  vector<vector<bool>> dp(sl + 1, vector<bool>(pl + 1, false));
  // if p == null, then s and p matches iff s == null
  dp[0][0] = true;

  for (int i = 1; i <= sl; i++) {
    dp[i][0] = false;
  }

  // if s == null, then s and p matches iff p conforms to (.*)*
  for (int j = 1; j <= pl; j++) {
    dp[0][j] = j > 1 && p[j - 1] == '*' && dp[0][j - 2];
  }

  for (int i = 1; i <= sl; i++) {
    for (int j = 1; j <= pl; j++) {
      if (p[j - 1] == '*') {
        dp[i][j] = dp[i][j - 2] || (isMatch(s[i - 1], p[j - 2]) && dp[i - 1][j]);
      } else {
        dp[i][j] = dp[i - 1][j - 1] && isMatch(s[i - 1], p[j - 1]);
      }
    }
  }

  return dp[sl][pl];
}

inline bool RegularExpressionMatching::isMatch(char _s, char _p)
{
  return _p == '.' || _s == _p;
}
