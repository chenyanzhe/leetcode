#include "LongestValidParentheses.hpp"

#include <vector>
using namespace std;

int LongestValidParentheses::longestValidParentheses(string s)
{
  int n = s.size();
  vector<int> dp(n + 1, 0);

  for (int i = 2; i <= n; i++) {
    if (s[i - 2] == '(' && s[i - 1] == ')')
      dp[i] = max(dp[i], dp[i - 2] + 2);

    if (s[i - 1] == ')' && i - dp[i - 1] - 2 >= 0
        && s[i - dp[i - 1] - 2] == '(')
      dp[i] = max(dp[i], dp[i - 1] + dp[i - dp[i - 1] - 2] + 2);
  }

  int ret = 0;

  for (int i = 2; i <= n; i++)
    ret = max(ret, dp[i]);

  return ret;
}
