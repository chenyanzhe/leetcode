#include "LongestPalindromicSubstring.hpp"

string LongestPalindromicSubstring::expandAroundCenter(string s, int c1,
    int c2)
{
  int l = c1;
  int r = c2;
  int n = s.size();

  while (l >= 0 && r <= n - 1 && s[l] == s[r]) {
    l--;
    r++;
  }

  return s.substr(l + 1, r - l - 1);
}
string LongestPalindromicSubstring::longestPalindrome(string s)
{
  int n = s.size();

  if (n == 0)
    return "";

  string result = s.substr(0, 1);

  for (int i = 0; i < n - 1; i++) {
    string p1 = expandAroundCenter(s, i, i);

    if (p1.size() > result.size())
      result = p1;

    string p2 = expandAroundCenter(s, i, i + 1);

    if (p2.size() > result.size())
      result = p2;
  }

  return result;
}
