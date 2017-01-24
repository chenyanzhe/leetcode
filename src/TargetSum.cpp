#include "TargetSum.hpp"

#include <numeric>

using namespace std;

int TargetSum::findTargetSumWays(vector<int>& nums, int S) {
    // sanity checks
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (S > sum || S < -sum)
        return 0;

    int ret = 0;
    dfs(nums, S, 0, 0, ret);

    return ret;
}

void TargetSum::dfs(vector<int>& nums, int S, int depth, int local, int& global) {
    if (depth == nums.size()) {
        if (local == S)
            global++;
        return;
    }

    dfs(nums, S, depth + 1, local + nums[depth], global);
    dfs(nums, S, depth + 1, local - nums[depth], global);
}
