#include "SubstringWithConcatenationOfAllWords.hpp"

#include <unordered_map>
using namespace std;

vector<int> SubstringWithConcatenationOfAllWords::findSubstring(string s, vector<string>& words)
{
  vector<int> ret;
  size_t strlen = s.size();
  size_t numw = words.size();

  if (strlen == 0 || numw == 0) return ret;

  size_t wlen = words[0].size();
  size_t substrlen = numw * wlen;

  if (wlen == 0 || substrlen > strlen) return ret;

  unordered_map<string, int> records;
  for (auto w : words)
    records[w]++;

  for (int p = 0; p + substrlen - 1 < strlen; p++) {
    unordered_map<string, int> local = records;
    int q;
    for (q = 0; q < numw; q++) {
      string seg = s.substr(p + q * wlen, wlen);
      if (local.find(seg) == local.end() || local[seg] == 0)
        break;
      else
        local[seg]--;
    }
    if (q == numw)
      ret.push_back(p);
  }

  return ret;
}
