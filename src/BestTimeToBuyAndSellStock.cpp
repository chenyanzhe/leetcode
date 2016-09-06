#include "BestTimeToBuyAndSellStock.hpp"

#include <algorithm>

using namespace std;

int BestTimeToBuyAndSellStock::maxProfit(vector<int> &prices) {
    if (prices.size() <= 1) return 0;

    int profit = 0;
    int minPrice = prices[0];
    for (int i = 1; i < prices.size(); i++) {
        profit = max(profit, prices[i] - minPrice);
        minPrice = min(minPrice, prices[i]);
    }

    return profit;
}
