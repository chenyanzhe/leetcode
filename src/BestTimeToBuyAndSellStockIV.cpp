#include "BestTimeToBuyAndSellStockIV.hpp"

using namespace std;

int BestTimeToBuyAndSellStockIV::maxProfit(int k, vector<int> &prices) {
    int n = prices.size();

    if (n <= 1)
        return 0;

    if (k >= n / 2) {
        // quick solve path
        int ret = 0;

        for (int i = 1; i < n; i++) {
            // as long as there is a price gap, we gain a profit
            if (prices[i] > prices[i - 1])
                ret += prices[i] - prices[i - 1];
        }

        return ret;
    }

    vector<vector<int>> dp(k + 1, vector<int>(n, 0));

    for (int i = 1; i <= k; i++) {
        int maxV = dp[i - 1][0] - prices[0];

        for (int j = 1; j < n; j++) {
            dp[i][j] = max(dp[i][j - 1], prices[j] + maxV);
            maxV = max(maxV, dp[i - 1][j] - prices[j]);
        }
    }

    return dp[k][n - 1];
}
