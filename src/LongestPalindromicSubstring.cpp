#include "LongestPalindromicSubstring.hpp"

string LongestPalindromicSubstring::longestPalindrome(string s)
{
  if (s.size() <= 2) return s;

  int len = 1;
  string ret = s.substr(0, 1);

  // even substring
  for (int i = 1; i < s.size(); i++) {
    if (s[i] != s[i - 1])
      continue;
    int j = 0;
    while (i - 1 - (j + 1) >= 0 &&
           i + (j + 1) < s.size() &&
           s[i - 1 - (j + 1)] == s[i + (j + 1)])
      j++;
    if (j * 2 + 2 > len) {
      len = j * 2 + 2;
      ret = s.substr(i - 1 - j, len);
    }
  }

  // odd substring
  for (int i = 1; i < s.size(); i++) {
    int j = 0;
    while (i - (j + 1) >= 0 &&
           i + (j + 1) < s.size() &&
           s[i - (j + 1)] == s[i + (j + 1)])
      j++;
    if (j * 2 + 1 > len) {
      len = j * 2 + 1;
      ret = s.substr(i - j, len);
    }
  }
  
  return ret;
}
