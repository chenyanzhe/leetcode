#include "WildcardMatching.hpp"

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

  while (si < sl && pi < pl) {
    if (p[pi] == '*') {
      while (pi < pl && p[pi] == '*')
        pi++;
      if (pi == pl) return true;
      while (si < sl) {
        if (isMatch(s[si], p[pi]) && isMatch(s.substr(si), p.substr(pi))) return true;
        si++;
      }
    } else if (isMatch(s[si], p[pi])) { 
      si++;
      pi++;
    } else
      return false;
  }

  return si == sl && pi == pl;
}

bool WildcardMatching::isMatch(char c, char p)
{
  return p == '?' || c == p;
}
