#include "DistinctSubsequences.hpp"

#include <vector>

using namespace std;

int DistinctSubsequences::numDistinct(string s, string t) {
    int ns = s.size();
    int nt = t.size();

    if (ns == 0 || nt == 0) return 0;

    vector<vector<int>> dp(ns + 1, vector<int>(nt + 1, 0));

    int count = 0;
    for (int i = 0; i < ns; i++) {
        if (s[i] == t[0])
            count++;
        dp[i + 1][1] = count;
    }

    for (int i = 0; i < ns; i++) {
        for (int j = 1; j < min(i + 1, nt); j++) {
            if (s[i] == t[j])
                dp[i + 1][j + 1] = dp[i][j + 1] + dp[i][j];
            else
                dp[i + 1][j + 1] = dp[i][j + 1];
        }
    }

    return dp[ns][nt];
}
