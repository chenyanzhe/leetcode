#include "LongestSubstringWithoutRepeatingCharacters.hpp"

#include <vector>
using namespace std;

int LongestSubstringWithoutRepeatingCharacters::lengthOfLongestSubstring(string s)
{
  if (s.size() == 0) return 0;

  vector<int> charMap(256, -1);
  int len = 1;
  size_t h = 0;
  charMap[s[0]] = 0;
  for (size_t i = 1; i < s.size(); i++) {
    int loc = charMap[s[i]];
    if (loc == -1) {
      len = (i - h + 1 > len ? i - h + 1 : len);
    } else {
      for (size_t j = h; j < loc; j++)
        charMap[s[j]] = -1;
      h = loc + 1;
    }
    charMap[s[i]] = i;
  }
  return len;
}
