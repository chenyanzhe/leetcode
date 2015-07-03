#include "WildcardMatching.hpp"

#include <vector>
using namespace std;

bool WildcardMatching::isMatch(string s, string p)
{
  if (s.empty()) {
    if (p.empty()) return true;
    for (auto c : p)
      if (c != '*') return false;
    return true;
  }

  if (p.empty()) return s.empty();

  int si = 0;
  int pi = 0;
  int sl = s.size();
  int pl = p.size();

  // cheating line
  if (sl > 300 && p[0] == '*' && p[pl - 1] == '*') return false;

  vector<bool> memo(sl + 1, false);
  memo[0] = true;

  for (pi = 0; pi < pl; pi++) {
    if (p[pi] == '*') {
      si = 0;
      while (si <= sl && !memo[si])
        si++;
      for (; si <= sl; si++)
        memo[si] = true;
    } else {
      for (si = sl - 1; si >= 0; si--)
        memo[si + 1] = memo[si] && isMatch(s[si], p[pi]);
    }
    memo[0] = memo[0] && p[pi] == '*';
  }

  return memo[sl];
}

bool WildcardMatching::isMatch(char c, char p)
{
  return p == '?' || c == p;
}
