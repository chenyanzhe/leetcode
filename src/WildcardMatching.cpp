#include "WildcardMatching.hpp"

#include <vector>

using namespace std;

bool WildcardMatching::isMatch(string s, string p) {
    int ns = s.size();
    int np = p.size();
    vector<vector<bool>> dp(ns + 1, vector<bool>(np + 1, false));
    dp[0][0] = true;

    for (int j = 1; j <= np; j++)
        dp[0][j] = dp[0][j - 1] && p[j - 1] == '*';

    for (int i = 1; i <= ns; i++) {
        for (int j = 1; j <= np; j++) {
            if (p[j - 1] == '*')
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            else
                dp[i][j] = (p[j - 1] == '?' || s[i - 1] == p[j - 1]) && dp[i - 1][j - 1];
        }
    }

    return dp[ns][np];
}
