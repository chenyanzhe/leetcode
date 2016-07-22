#include "Triangle.hpp"

int Triangle::minimumTotal(vector<vector<int>> &triangle) {
    int n = triangle.size();

    if (n == 0)
        return 0;

    vector<int> dp(n, 0);
    dp[0] = triangle[0][0];

    for (int i = 1; i < n; i++) {
        int oldv = dp[0];
        dp[0] = triangle[i][0] + dp[0];

        for (int j = 1; j < i; j++) {
            int newv = dp[j];
            dp[j] = triangle[i][j] + min(dp[j], oldv);
            oldv = newv;
        }

        dp[i] = triangle[i][i] + oldv;
    }

    int ret = dp[0];

    for (int j = 1; j < n; j++)
        ret = min(ret, dp[j]);

    return ret;
}
