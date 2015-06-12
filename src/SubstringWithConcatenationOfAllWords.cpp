#include "SubstringWithConcatenationOfAllWords.hpp"

#include <unordered_map>
using namespace std;

vector<int> SubstringWithConcatenationOfAllWords::findSubstring(string s, vector<string>& words)
{
  vector<int> ret;
  size_t seglen = words[0].size();
  size_t nsegs = words.size();
  if (nsegs == 0 || s.size() == 0 || seglen == 0 || seglen * nsegs > s.size())
    return ret;

  unordered_map<string, int> records;
  for (auto w : words)
    records[w]++;

  int p = 0;
  while (p + seglen * nsegs - 1 < s.size()) {
    unordered_map<string, int> local = records;
    int i;
    for (i = 0; i < nsegs; i++) {
      string seg = s.substr(p + i * seglen, seglen);
      if (local.find(seg) == local.end() || local[seg] == 0)
        break;
      else
        local[seg]--;
    }
    if (i == nsegs)
      ret.push_back(p);
    p++;
  }

  return ret;
}
