#include "LongestValidParentheses.hpp"

#include <vector>

using namespace std;

int LongestValidParentheses::longestValidParentheses(string s) {
    int len = s.size();
    vector<int> dp(len, 0);
    int ret = 0;

    for (int i = 1; i < len; i++) {
        if (s[i] == '(') continue;
        if (s[i - 1] == '(')
            dp[i] = (i == 1 ? 2 : dp[i - 2] + 2);
        else if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(')
            dp[i] = dp[i - 1] + 2 + (i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0);

        ret = max(ret, dp[i]);
    }

    return ret;
}
