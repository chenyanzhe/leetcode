#include "BestTimeToBuyAndSellStockWithCooldown.hpp"

int BestTimeToBuyAndSellStockWithCooldown::maxProfit(vector<int> &prices) {
    size_t n = prices.size();
    if (n <= 1) return 0;

    vector<int> buy(n + 1, 0);
    vector<int> sell(n + 1, 0);
    buy[1] = -prices[0];

    for (int i = 2; i <= n; i++) {
        int diff = prices[i - 1] - prices[i - 2];
        sell[i] = max(buy[i - 1] + prices[i - 1], sell[i - 1] + diff);
        buy[i] = max(sell[i - 2] - prices[i - 1], buy[i - 1] - diff);
    }

    int profit = 0;

    for (int i = 0; i <= n; i++)
        profit = max(profit, sell[i]);

    return profit;
}
