#include "Anagrams.hpp"

#include <unordered_map>
#include <algorithm>
using namespace std;

vector<string> Anagrams::anagrams(vector<string>& strs)
{
  vector<string> ret;

  unordered_map<string, int> rec;
  for (int i = 0; i < strs.size(); i++) {
    string ss = strs[i];
    sort(ss.begin(), ss.end());
    if (rec.find(ss) != rec.end()) {
      ret.push_back(strs[i]);
      if (rec[ss] != -1) {
        ret.push_back(strs[rec[ss]]);
        rec[ss] = -1;
      }
    } else {
      rec[ss] = i;
    }
  }

  return ret;
}
