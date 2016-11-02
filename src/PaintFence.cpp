#include "PaintFence.hpp"

#include <vector>

using namespace std;

int PaintFence::numWays(int n, int k) {
    if (n == 0 || k == 0) return 0;
    if (n == 1) return k;

    vector<int> dp(n, 0);
    dp[0] = k;
    dp[1] = k * k;

    for (int i = 2; i < n; i++)
        dp[i] = (k - 1) * dp[i - 1] + (k - 1) * dp[i - 2];

    return dp[n - 1];
}
