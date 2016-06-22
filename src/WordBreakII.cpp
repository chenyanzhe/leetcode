#include "WordBreakII.hpp"

vector<string> WordBreakII::wordBreak(string s,
                                      unordered_set<string>& wordDict)
{
  if (s.size() == 0)
    return vector<string>();

  unordered_map<string, vector<string>> map;
  return dfs(s, wordDict, map);
}

vector<string> WordBreakII::dfs(string s, unordered_set<string>& dict,
                                unordered_map<string, vector<string>>& map)
{
  if (map.find(s) != map.end())
    return map[s];

  vector<string> ans;

  if (s.size() == 0)
    ans.push_back("");
  else {
    for (int i = 1; i <= s.size(); i++) {
      string l = s.substr(0, i);

      if (dict.find(l) == dict.end())
        continue;

      vector<string> rans = dfs(s.substr(i), dict, map);

      for (auto r : rans) {
        string lr = l;

        if (i != s.size())
          lr += " ";

        lr += r;
        ans.push_back(lr);
      }
    }
  }

  map[s] = ans;
  return ans;
}
