#include "DungeonGame.hpp"

#include <algorithm>
using namespace std;

int DungeonGame::calculateMinimumHP(vector<vector<int>>& dungeon)
{
    int m = dungeon.size();
    if (m == 0) return 0;
    int n = dungeon[0].size();
    if (n == 0) return 0;

    vector<vector<int>> dp(m, vector<int>(n, 0));

    dp[m-1][n-1] = (dungeon[m-1][n-1] >= 0) ? 1 : (1 - dungeon[m-1][n-1]);

    for (int i = m - 2; i >= 0; i--) {
        if (dp[i+1][n-1] - dungeon[i][n-1] <= 0)
            dp[i][n-1] = 1;
        else
            dp[i][n-1] = dp[i+1][n-1] - dungeon[i][n-1];
    }

    for (int j = n - 2; j >= 0; j--) {
        if (dp[m-1][j+1] - dungeon[m-1][j] <= 0)
            dp[m-1][j] = 1;
        else
            dp[m-1][j] = dp[m-1][j+1] - dungeon[m-1][j];
    }

    for (int i = m - 2; i >= 0; i--) {
        for (int j = n - 2; j >= 0; j--) {
            int base = min(dp[i+1][j], dp[i][j+1]);
            if (base - dungeon[i][j] <= 0)
                dp[i][j] = 1;
            else
                dp[i][j] = base - dungeon[i][j];
        }
    }

    return dp[0][0];
}