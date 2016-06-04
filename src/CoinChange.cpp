#include "CoinChange.hpp"

#include <climits>
using namespace std;

int CoinChange::coinChange(vector<int>& coins, int amount)
{
  if (amount <= 0) {
    return 0;
  }

  vector<int> items;

  for (auto c : coins) {
    if (c < amount) {
      items.push_back(c);
    } else if (c == amount) {
      return 1;
    }
  }

  vector<int> dp(amount + 1, INT_MAX);
  dp[0] = 0;

  for (int i = 0; i < items.size(); i++) {
    for (int v = items[i]; v <= amount; v++) {
      dp[v] = min(dp[v], (dp[v - items[i]] == INT_MAX) ? INT_MAX : dp[v - items[i]] +
                  1);
    }
  }

  return dp[amount] == INT_MAX ? -1 : dp[amount];
}