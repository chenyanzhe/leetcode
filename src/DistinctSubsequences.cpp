#include "DistinctSubsequences.hpp"

#include <vector>

using namespace std;

int DistinctSubsequences::numDistinct(string s, string t) {
    int ns = s.size();
    int nt = t.size();

    if (ns == 0 || nt == 0) return 0;

    vector<vector<int>> dp(ns, vector<int>(nt, 0));
    int k = 0;

    for (int i = 0; i < ns; i++) {
        if (t[0] == s[i])
            k++;

        dp[i][0] = k;
    }

    for (int j = 1; j < nt; j++)
        dp[0][j] = 0;

    for (int i = 1; i < ns; i++) {
        for (int j = 1; j < min(i + 1, nt); j++) {
            if (s[i] == t[j])
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[ns - 1][nt - 1];
}
