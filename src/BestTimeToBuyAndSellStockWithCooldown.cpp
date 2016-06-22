#include "BestTimeToBuyAndSellStockWithCooldown.hpp"

#include <algorithm>
#include <climits>
using namespace std;

int BestTimeToBuyAndSellStockWithCooldown::maxProfit(vector<int>& prices)
{
  int n = prices.size();

  if (n <= 1)
    return 0;

  int tMin = min(prices[1], prices[0]);
  int tMax = INT_MIN;
  vector<int> dp(n, 0);
  dp[1] = max(prices[1] - prices[0], 0);

  for (int i = 2; i < n; i++) {
    dp[i] = max(dp[i - 1], prices[i] - tMin);
    dp[i] = max(dp[i], prices[i] + tMax);
    tMax = max(tMax, dp[i - 2] - prices[i]);
  }

  return dp[n - 1];
}
