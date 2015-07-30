#include "BestTimeToBuyAndSellStock.hpp"

int BestTimeToBuyAndSellStock::maxProfit(vector<int>& prices)
{
  int sz = prices.size();
  if (sz <= 1) return 0;

  int ret = 0;
  vector<int> dp(sz + 1, 0);
  for (int i = 2; i <= sz; i++) {
    dp[i] = dp[i - 1] + prices[i - 1] - prices[i - 2];
    if (dp[i] < 0)
      dp[i] = 0;
    else if (ret < dp[i])
      ret = dp[i];
  }

  return ret;
}
