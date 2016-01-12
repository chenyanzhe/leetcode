#include "LengthOfLastWord.hpp"

int LengthOfLastWord::lengthOfLastWord(string s)
{
  bool inWord = false;
  int len = 0;

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == ' ' && inWord) {
      inWord = false;
    } else if (s[i] != ' ') {
      len = inWord ? len + 1 : 1;
      inWord = true;
    }
  }

  return len;
}
