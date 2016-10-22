#include "BestTimeToBuyAndSellStockIII.hpp"

using namespace std;

int BestTimeToBuyAndSellStockIII::maxProfit(vector<int> &prices) {
    if (prices.size() <= 1) return 0;

    size_t n = prices.size();

    vector<int> preProfit(n, 0);
    int minPrice = prices[0];
    for (int i = 1; i < n; i++) {
        preProfit[i] = max(preProfit[i - 1], prices[i] - minPrice);
        minPrice = min(minPrice, prices[i]);
    }

    vector<int> postProfit(n, 0);
    int maxPrice = prices[n - 1];
    for (int i = 1; i < n; i++) {
        postProfit[n - 1 - i] = max(postProfit[n - i], maxPrice - prices[n - 1 - i]);
        maxPrice = max(maxPrice, prices[n - 1 - i]);
    }

    int profit = 0;
    for (int i = 0; i < n; i++) {
        profit = max(profit, preProfit[i] + postProfit[i]);
    }

    return profit;
}
