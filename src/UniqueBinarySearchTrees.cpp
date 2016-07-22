#include "UniqueBinarySearchTrees.hpp"

#include <vector>

using namespace std;

int UniqueBinarySearchTrees::numTrees(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            dp[i] += dp[j - 1] * dp[i - j];

    return dp[n];
}
