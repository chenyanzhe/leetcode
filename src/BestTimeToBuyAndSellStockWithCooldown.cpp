#include "BestTimeToBuyAndSellStockWithCooldown.hpp"

#include <algorithm>

using namespace std;

int BestTimeToBuyAndSellStockWithCooldown::maxProfit(vector<int> &prices) {
    int n = prices.size();
    if (n <= 1) return 0;

    vector<int> buy(n + 1, 0);
    vector<int> sell(n + 1, 0);
    buy[1] = -prices[0];

    for (int i = 1; i < n; i++) {
        sell[i + 1] = max(buy[i] + prices[i], sell[i] - prices[i - 1] + prices[i]);
        buy[i + 1] = max(sell[i - 1] - prices[i], buy[i] + prices[i - 1] - prices[i]);
    }

    int profit = 0;

    for (int i = 0; i <= n; i++)
        profit = max(profit, sell[i]);

    return profit;
}
