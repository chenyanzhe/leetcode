#include "WildcardMatching.hpp"

bool WildcardMatching::isMatch(string s, string p)
{
  if (s.empty()) {
    if (p.empty())
      return true;
    for (auto c : p)
      if (c != '*')
        return false;
    return true;
  }

  if (p.empty())
    return s.empty();

  int i;
  int j;
  int k;
  switch(p[0]) {
  case '?':
    // fetching continuous ?
    j = 1;
    while (j < p.size() && p[j] == '*')
      j++;
    if (s.size() < j)
      return false;
    return isMatch(s.substr(j), p.substr(j));
    break;
  case '*':
    // fetching continuous *
    j = 1;
    while (j < p.size() && p[j] == '*')
      j++;
    k = p.size() - 1;
    for (i = 0; i <= s.size(); i++)
      if (isMatch(s.substr(i), p.substr(j)))
        return true;
    return false;
    break;
  default:
    return (s[0] == p[0]) && isMatch(s.substr(1), p.substr(1));
  }
}
