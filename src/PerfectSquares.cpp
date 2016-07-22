#include "PerfectSquares.hpp"

#include <vector>

using namespace std;

int PerfectSquares::numSquares(int n) {
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];

        for (int j = 2; j * j <= i; j++)
            dp[i] = min(dp[i], dp[i - j * j]);

        dp[i] += 1;
    }

    return dp[n];
}
