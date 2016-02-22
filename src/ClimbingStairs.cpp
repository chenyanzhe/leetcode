#include "ClimbingStairs.hpp"

#include <vector>
using namespace std;

int ClimbingStairs::climbStairs(int n)
{
  if (n == 0 || n == 1 || n == 2) {
    return n;
  }

  vector<int> dp(n, 0);
  dp[0] = 1;
  dp[1] = 2;

  for (int i = 2; i < n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }

  return dp[n - 1];
}
