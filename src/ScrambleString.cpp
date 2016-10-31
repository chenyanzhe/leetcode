#include "ScrambleString.hpp"

#include <vector>

using namespace std;

bool ScrambleString::isScramble(string s1, string s2) {
    if (s1.size() != s2.size()) return false;

    if (s1 == s2) return true;

    size_t n = s1.size();
    vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(n + 1, false)));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dp[i][j][1] = (s1[i] == s2[j]);

    for (int k = 2; k <= n; k++) {
        for (int i = 0; i <= n - k; i++) {
            for (int j = 0; j <= n - k; j++) {
                for (int m = 1; m < k; m++) {
                    if ((dp[i][j][m] && dp[i + m][j + m][k - m]) ||
                        (dp[i][j + k - m][m] && dp[i + m][j][k - m]))
                        dp[i][j][k] = true;
                }
            }
        }
    }

    return dp[0][0][n];
}
