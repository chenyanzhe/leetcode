#include "LongestValidParentheses.hpp"

#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int LongestValidParentheses::longestValidParentheses(string s)
{
  if (s.size() < 2) return 0;

  vector<int> dp(s.size(), 0);

  for (int i = 1; i < s.size(); i++) {
    if (s[i] == '(') dp[i] = 0;
    else { // s[i] = ')'
      int j = i - dp[i - 1];
      if (j - 1 >= 0 && s[j - 1] == '(')
        dp[i] = (j - 2 >= 0) ? dp[i - 1] + dp[j - 2] + 2 : dp[i - 1] + 2;
      else
        dp[i] = 0;
    }
  }
  return *(max_element(dp.begin(), dp.end()));
}
