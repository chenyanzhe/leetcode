#include "WordBreak.hpp"

#include <vector>
using namespace std;

bool WordBreak::wordBreak(string s, unordered_set<string>& wordDict)
{
  int sz = s.size();

  vector<bool> dp(sz + 1, false);
  dp[0] = true;

  for (int i = 1; i <= sz; i++) {
    for (int j = 0; j < i; j++) {
      if (dp[j] && wordDict.find(s.substr(j, i - j)) != wordDict.end()) {
        dp[i] = true;
        break;
      }
    }
  }

  return dp[sz];
}
