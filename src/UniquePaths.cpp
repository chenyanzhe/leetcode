#include "UniquePaths.hpp"

#include <vector>

using namespace std;

int UniquePaths::uniquePaths(int m, int n) {
    if (m == 0 || n == 0)
        return 0;

    vector<int> dp(n, 1);

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++)
            dp[j] += dp[j - 1];
    }

    return dp[n - 1];
}

