#include "BestTimeToBuyAndSellStock.hpp"

using namespace std;

int BestTimeToBuyAndSellStock::maxProfit(vector<int> &prices) {
    int sz = prices.size();

    if (sz <= 1)
        return 0;

    int result = 0;
    int min_price = prices[0];

    for (int i = 1; i < sz; i++) {
        result = max(result, prices[i] - min_price);
        min_price = min(min_price, prices[i]);
    }

    return result;
}
