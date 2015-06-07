#include "RomanToInteger.hpp"

#include <iostream>
using namespace std;

int RomanToInteger::romanToInt(string s)
{
  if (s.empty()) return 0;

  int i;
  switch(s[0]) {
  case 'M':
    i = 0;
    while (i + 1 < s.size() && s[i + 1] == 'M')
      i++;
    return cheatMap[3][s.substr(0, i + 1)] + romanToInt(s.substr(i + 1));
  case 'C':
  case 'D':
    i = 0;
    while (i + 1 < s.size() &&
        (s[i + 1] == 'C' || s[i + 1] == 'D' || s[i + 1] == 'M'))
      i++;
    return cheatMap[2][s.substr(0, i + 1)] + romanToInt(s.substr(i + 1));
  case 'X':
  case 'L':
    i = 0;
    while (i + 1 < s.size() &&
        (s[i + 1] == 'X' || s[i + 1] == 'L' || s[i + 1] == 'C'))
      i++;
    return cheatMap[1][s.substr(0, i + 1)] + romanToInt(s.substr(i + 1));
  case 'I':
  case 'V':
    i = 0;
    while (i + 1 < s.size() &&
        (s[i + 1] == 'I' || s[i + 1] == 'V' || s[i + 1] == 'X'))
      i++;
    return cheatMap[0][s.substr(0, i + 1)] + romanToInt(s.substr(i + 1));
  }
  return 0;
}
