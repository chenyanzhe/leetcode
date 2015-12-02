#include "BestTimeToBuyAndSellStockIV.hpp"

#include <algorithm>
using namespace std;

int BestTimeToBuyAndSellStockIV::maxProfit(int k, vector<int>& prices)
{
    /**
     * local[i][j]: i day, j txn, jth txn happened at day i
     * global[i][j]: i day, j txn
     *
     * diff = prices[i] - prices[i-1]
     * local[i][j] = max(global[i-1][j-1] + max(diff, 0), local[i-1][j] + diff)
     * global[i][j] = max(global[i-1][j], local[i][j])
     */

    int days = prices.size();

    if (days <= 1) return 0;
    if (k >= days) return maxProfitNoLimits(prices);

    vector<int> local(k + 1, 0);
    vector<int> global(k + 1, 0);
    for (int i = 1; i < days; i++) {
        for (int j = k; j >= 1; j--) {
            int diff = prices[i] - prices[i-1];
            local[j] = max(global[j-1] + max(diff, 0), local[j] + diff);
            global[j] = max(global[j], local[j]);
        }
    }

    return global[k];
}

int BestTimeToBuyAndSellStockIV::maxProfitNoLimits(vector<int>& prices)
{
    int result = 0;
    for (int i = 1; i < prices.size(); i++) {
        int diff = prices[i] - prices[i-1];
        if (diff > 0) result += diff;
    }
    return result;
}
