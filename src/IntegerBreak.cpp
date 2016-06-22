#include "IntegerBreak.hpp"

#include <vector>
using namespace std;

int IntegerBreak::integerBreak(int n)
{
  vector<int> dp(n + 1, 0);
  dp[1] = 1;

  for (int i = 2; i <= n; i++) {
    for (int k = 1; k <= i - 1; k++)
      dp[i] = max(dp[i], k * max(i - k, dp[i - k]));
  }

  return dp[n];
}
