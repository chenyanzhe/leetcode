#include "CoinChange.hpp"

#include <climits>
#include <algorithm>
using namespace std;

int CoinChange::coinChange(vector<int>& coins, int amount)
{
  if (amount < 0 || coins.empty())
    return -1;

  vector<int> dp(amount + 1, INT_MAX);
  dp[0] = 0;

  for (auto c : coins) {
    for (auto i = c; i <= amount; i++) {
      if (dp[i - c] != INT_MAX)
        dp[i] = min(dp[i - c] + 1, dp[i]);
    }
  }

  return dp[amount] == INT_MAX ? -1 : dp[amount];
}
