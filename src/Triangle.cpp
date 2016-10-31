#include "Triangle.hpp"

int Triangle::minimumTotal(vector<vector<int>> &triangle) {
    if (triangle.empty()) return 0;

    size_t n = triangle.size();

    if (triangle[n - 1].size() != n) return 0;

    vector<vector<int>> dp(n, vector<int>(n, 0));

    dp[0][0] = triangle[0][0];

    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][0] + triangle[i][0];
        dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < i; j++) {
            dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
        }
    }

    int ret = INT_MAX;

    for (int j = 0; j < n; j++)
        ret = min(ret, dp[n - 1][j]);

    return ret;
}
