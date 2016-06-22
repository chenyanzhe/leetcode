#include "IsomorphicStrings.hpp"

#include <unordered_map>
using namespace std;

bool IsomorphicStrings::isIsomorphic(string s, string t)
{
  if (s.size() != t.size())
    return false;

  remap(s);
  remap(t);
  return s == t;
}

void IsomorphicStrings::remap(string& s)
{
  unordered_map<char, char> mappings;
  char c = '0';

  for (int i = 0; i < s.size(); i++) {
    if (mappings.find(s[i]) == mappings.end()) {
      mappings[s[i]] = c;
      s[i] = c;
      c++;
    } else
      s[i] = mappings[s[i]];
  }
}
