#include "FrogJump.hpp"

#include <map>
#include <set>

using namespace std;

bool FrogJump::canCross(vector<int> &stones) {
    if (stones.size() <= 1) return true;

    if (stones[1] != 1) return false;

    size_t n = stones.size();
    vector<bool> canReach(n, false);
    vector<set<int>> jumpSteps(n);
    map<int, int> stoneMap;

    canReach[1] = true;
    jumpSteps[1].insert(1);

    for (int i = 0; i < stones.size(); i++)
        stoneMap[stones[i]] = i;

    int farest = 1;
    for (int i = 1; i < n && i <= farest; i++) {
        for (auto step : jumpSteps[i]) {
            if (step - 1 > 0) {
                int nextStone = stones[i] + step - 1;
                if (stoneMap.find(nextStone) != stoneMap.end()) {
                    int j = stoneMap[nextStone];
                    farest = max(farest, j);
                    canReach[j] = true;
                    jumpSteps[j].insert(step - 1);
                }
            }

            if (step > 0) {
                int nextStone = stones[i] + step;
                if (stoneMap.find(nextStone) != stoneMap.end()) {
                    int j = stoneMap[nextStone];
                    farest = max(farest, j);
                    canReach[j] = true;
                    jumpSteps[j].insert(step);
                }
            }

            if (step + 1 > 0) {
                int nextStone = stones[i] + step + 1;
                if (stoneMap.find(nextStone) != stoneMap.end()) {
                    int j = stoneMap[nextStone];
                    farest = max(farest, j);
                    canReach[j] = true;
                    jumpSteps[j].insert(step + 1);
                }
            }
        }
    }

    return canReach[n - 1];
}
