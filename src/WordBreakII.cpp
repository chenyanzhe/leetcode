#include "WordBreakII.hpp"

vector<string> WordBreakII::wordBreak(string s,
                                      unordered_set<string>& wordDict)
{
  int n = s.size();

  if (n == 0) return vector<string>();

  unordered_map<string, vector<string>> cache;
  return wordBreak_helper(s, wordDict, cache);
}

vector<string> WordBreakII::wordBreak_helper(string s,
    unordered_set<string>& wordDict, unordered_map<string, vector<string>>& cache)
{
  if (cache.count(s))
    return cache[s];

  vector<string> ret;

  if (wordDict.count(s))
    ret.push_back(s);

  int n = s.size();

  for (int i = 1; i <= n - 1; i++) {
    string prefix = s.substr(0, i);
    string postfix = s.substr(i, n - i);

    if (wordDict.count(prefix)) {
      vector<string> posts = wordBreak_helper(postfix, wordDict, cache);

      for (auto p : posts)
        ret.push_back(prefix + " " + p);
    }
  }

  cache[s] = ret;
  return ret;
}
