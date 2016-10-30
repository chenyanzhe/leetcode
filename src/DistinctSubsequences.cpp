#include "DistinctSubsequences.hpp"

#include <vector>

using namespace std;

int DistinctSubsequences::numDistinct(string s, string t) {
    int ns = s.size();
    int nt = t.size();

    vector<vector<int>> dp(ns + 1, vector<int>(nt + 1, 0));

    for (int i = 0; i <= ns; i++)
        dp[i][0] = 1;

    for (int j = 1; j <= nt; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= ns; i++) {
        for (int j = 1; j <= min(i, nt); j++) {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[ns][nt];
}
