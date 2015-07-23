#include "LongestValidParentheses.hpp"

#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int LongestValidParentheses::longestValidParentheses(string s)
{
  if (s.size() < 2) return 0;

  vector<int> dp(s.size(), 0);
  int ret = 0;

  for (int i = 1; i < s.size(); i++) {
    if (s[i] == '(') continue;
    if (s[i - 1] == '(') {
      dp[i] = 2;
      if (i - 2 >= 0)
        dp[i] += dp[i - 2];
    }
    else {
      int jump = dp[i - 1];
      if (i - jump - 1 >= 0 && s[i - jump - 1] == '(') {
        dp[i] = jump + 2;
        if (i - jump - 2 >= 0)
          dp[i] += dp[i - jump - 2];
      }
    }
    ret = (dp[i] > ret) ? dp[i] : ret;
  }
  return ret;
}
