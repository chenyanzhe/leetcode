#include "PaintHouseII.hpp"

#include <climits>

using namespace std;

int PaintHouseII::minCostII(vector<vector<int>> &costs) {
    if (costs.empty()) return 0;

    int minCosts = INT_MAX, minCostsIdx = -1;
    int secondMinCosts = INT_MAX;

    for (int j = 0; j < costs[0].size(); j++) {
        if (costs[0][j] < minCosts) {
            secondMinCosts = minCosts;
            minCosts = costs[0][j];
            minCostsIdx = j;
        } else if (costs[0][j] < secondMinCosts) {
            secondMinCosts = costs[0][j];
        }
    }

    for (int i = 1; i < costs.size(); i++) {
        int nextMinCosts = INT_MAX, nextMinCostsIdx = -1;
        int nextSecondMinCosts = INT_MAX;
        for (int j = 0; j < costs[0].size(); j++) {
            costs[i][j] += (j == minCostsIdx) ? secondMinCosts : minCosts;

            if (costs[i][j] < nextMinCosts) {
                nextSecondMinCosts = nextMinCosts;
                nextMinCosts = costs[i][j];
                nextMinCostsIdx = j;
            } else if (costs[i][j] < nextSecondMinCosts) {
                nextSecondMinCosts = costs[i][j];
            }
        }

        minCosts = nextMinCosts;
        minCostsIdx = nextMinCostsIdx;
        secondMinCosts = nextSecondMinCosts;
    }

    int ret = INT_MAX;

    for (int j = 0; j < costs[0].size(); j++)
        ret = min(ret, costs[costs.size() - 1][j]);

    return ret;
}
