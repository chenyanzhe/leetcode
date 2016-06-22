#include "BestTimeToBuyAndSellStockII.hpp"

int BestTimeToBuyAndSellStockII::maxProfit(vector<int>& prices)
{
  int sz = prices.size();

  if (sz <= 1)
    return 0;

  int result = 0;

  for (int i = 1; i < sz; i++) {
    int diff = prices[i] - prices[i - 1];

    if (diff > 0)
      result += diff;
  }

  return result;
}
