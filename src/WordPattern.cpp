#include "WordPattern.hpp"

#include <vector>
#include <unordered_map>
using namespace std;

bool WordPattern::wordPattern(string pattern, string str)
{
  vector<string> ptable(256, "");
  unordered_map<string, char> wtable;
  int i = 0;
  int j = 0;

  for (auto c : pattern) {
    if (j >= str.size()) {
      return false;
    }

    while (j < str.size() && str[j] != ' ') {
      j++;
    }

    string w = str.substr(i, j - i);

    if (ptable[c] == "") {
      ptable[c] = w;
    } else if (ptable[c] != w) {
      return false;
    }

    if (wtable.find(w) == wtable.end()) {
      wtable[w] = c;
    } else if (wtable[w] != c) {
      return false;
    }

    i = j + 1;
    j = i;
  }

  return j >= str.size();
}