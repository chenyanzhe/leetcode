#include "BestTimeToBuyAndSellStockIII.hpp"

int BestTimeToBuyAndSellStockIII::maxProfit(vector<int> &prices) {
    if (prices.size() <= 1) return 0;

    size_t n = prices.size();
    size_t k = 2;

    vector<vector<int>> global(n + 1, vector<int>(k + 1, 0));
    vector<vector<int>> local(n + 1, vector<int>(k + 1, 0));

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= 2; j++) {
            int diff = prices[i - 1] - prices[i - 2];
            local[i][j] = max(local[i - 1][j] + diff, global[i - 1][j - 1] + max(diff, 0));
            global[i][j] = max(global[i - 1][j], local[i][j]);
        }
    }

    return global[n][k];
}
