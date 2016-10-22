#include "BestTimeToBuyAndSellStockIV.hpp"

#include <algorithm>

using namespace std;

int BestTimeToBuyAndSellStockIV::maxProfit(int k, vector<int> &prices) {
    int n = prices.size();

    if (n <= 1)
        return 0;

    if (k >= n / 2) {
        // In this case, we can complete as many transactions as we like
        // See also: Best Time to Buy and Sell Stock II
        int ret = 0;

        for (int i = 1; i < n; i++) {
            if (prices[i] > prices[i - 1])
                ret += prices[i] - prices[i - 1];
        }

        return ret;
    }

    vector<vector<int>> local(n, vector<int>(k + 1, 0));
    vector<vector<int>> global(n, vector<int>(k + 1, 0));
    for (int i = 1; i < n; i++) {
        int diff = prices[i] - prices[i - 1];
        for (int j = 1; j <= k; j++) {
            local[i][j] = max(global[i - 1][j - 1] + max(diff, 0), local[i - 1][j] + diff);
            global[i][j] = max(global[i - 1][j], local[i][j]);
        }
    }

    return global[n - 1][k];
}
