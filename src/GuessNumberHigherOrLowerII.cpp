#include "GuessNumberHigherOrLowerII.hpp"

#include <vector>

using namespace std;

int GuessNumberHigherOrLowerII::getMoneyAmount(int n) {
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int l = 2; l <= n; l++) {
        for (int i = 1; i + l - 1 <= n; i++) {
            int j = i + l - 1;
            dp[i][j] = min(i + dp[i + 1][j], j + dp[i][j - 1]);
            for (int k = i + 1; k < j; k++) {
                dp[i][j] = min(dp[i][j], max(k + dp[i][k - 1], k + dp[k + 1][j]));
            }
        }
    }

    return dp[1][n];
}
