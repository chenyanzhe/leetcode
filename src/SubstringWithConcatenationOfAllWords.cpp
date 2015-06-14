#include "SubstringWithConcatenationOfAllWords.hpp"

#include <unordered_map>
using namespace std;

vector<int> SubstringWithConcatenationOfAllWords::findSubstring(string s, vector<string>& words)
{
  vector<int> ret;
  size_t slen = s.size();
  size_t wslen = words.size();

  if (slen == 0 || wslen == 0) return ret;

  size_t wlen = words[0].size();
  size_t sslen = wlen * wslen;

  if (wlen == 0 || sslen > slen) return ret;

  unordered_map<string, int> records;
  for (auto w : words)
    records[w]++;

  for (int h = 0; h < wlen && h + sslen <= slen; h++) {
    int lp = h;
    int rp = h;
    unordered_map<string, int> occurs;
    while (lp + sslen <= slen) {
      string seg = s.substr(rp, wlen);
      if (records.find(seg) == records.end()) {
        for (; lp < rp; lp += wlen)
          occurs[s.substr(lp, wlen)]--;
        lp = rp + wlen;
        rp = lp;
      }
      else if (occurs[seg] == records[seg]) {
        for (; s.substr(lp, wlen) != seg; lp += wlen)
          occurs[s.substr(lp, wlen)]--;
        lp += wlen;
        rp += wlen;
      }
      else {
        occurs[seg]++;
        rp += wlen;
        if (rp - lp == sslen) {
          ret.push_back(lp);
          occurs[s.substr(lp, wlen)]--;
          lp += wlen;
        }
      }
    }
  }

  return ret;
}
