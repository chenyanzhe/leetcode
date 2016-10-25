#include "Triangle.hpp"

int Triangle::minimumTotal(vector<vector<int>> &triangle) {
    if (triangle.empty()) return 0;

    int n = triangle.size();
    vector<int> dp(n, 0);

    for (int i = 0; i < n; i++)
        dp[i] = triangle[n - 1][i];

    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
        }
    }

    return dp[0];
}
