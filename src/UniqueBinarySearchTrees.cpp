#include "UniqueBinarySearchTrees.hpp"

#include <vector>
using namespace std;

int UniqueBinarySearchTrees::numTrees(int n)
{
  if (n < 0) return 0;

  vector<int> dp(n + 1, 0);
  dp[0] = 1;

  for (int i = 1; i <= n; i++)
    for (int r = 1; r <= i; r++)
      dp[i] += dp[r-1] * dp[i-r];

  return dp[n];
}
