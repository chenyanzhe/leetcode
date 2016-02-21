#include "GroupAnagrams.hpp"

#include <unordered_map>
#include <algorithm>
using namespace std;

vector<vector<string>> GroupAnagrams::groupAnagrams(vector<string>& strs)
{
  vector<vector<string>> ret;
  unordered_map<string, vector<string>> rec;

  for (auto s : strs) {
    string key = s;
    sort(key.begin(), key.end());
    rec[key].push_back(s);
  }
  
  for (auto p : rec) {
    sort(p.second.begin(), p.second.end());
    ret.push_back(p.second);
  }

  return ret;
}
