#include "ValidAnagram.hpp"

bool ValidAnagram::isAnagram(string s, string t)
{
  if (s.size() != t.size()) return false;
        
  int cnts[256];
  for (int i = 0; i < 256; i++)
    cnts[i] = 0;
  for (int i = 0; i < s.size(); i++)
    cnts[s[i]]++;
  for (int i = 0; i < t.size(); i++) {
    if (cnts[t[i]] == 0) return false;
    cnts[t[i]]--;
  }
  return true;
}