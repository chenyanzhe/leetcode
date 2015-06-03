#include "RegularExpressionMatching.hpp"

bool Solution::isMatch(string s, string p)
{
  if (p.empty()) return s.empty();
  if (s.empty()) return p.empty() || (p.size() >= 2 && p[1] == '*' && isMatch(s, p.substr(2)));

  if (p.size() == 1) {
    return s.size() == 1 && (p[0] == '.' || p[0] == s[0]);
  } else if (p[1] == '*') {
    if (p[0] == '.') {
      if (isMatch(s, p.substr(2))) return true;
      for (int i = 1; i <= s.size(); i++)
        if (isMatch(s.substr(i), p.substr(2))) return true;
      return false;
    } else {
      if (isMatch(s, p.substr(2))) return true;
      for (int i = 0; i < s.size() && s[i] == p[0]; i++)
        if (isMatch(s.substr(i + 1), p.substr(2))) return true;
      return false;
    }
  } else {
    return isMatch(s.substr(1), p.substr(1)) && (p[0] == '.' || p[0] == s[0]);
  }
  return false;
}
