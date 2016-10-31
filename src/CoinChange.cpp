#include "CoinChange.hpp"

#include <climits>

using namespace std;

int CoinChange::coinChange(vector<int> &coins, int amount) {
    if (amount < 0 || coins.empty())
        return -1;

    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
        for (auto c : coins)
            if (c <= i && dp[i - c] < INT_MAX)
                dp[i] = min(dp[i], dp[i - c] + 1);

    return dp[amount] == INT_MAX ? -1 : dp[amount];
}
