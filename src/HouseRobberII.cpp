#include "HouseRobberII.hpp"

using namespace std;

int HouseRobberII::rob(vector<int> &nums) {
    int sz = nums.size();

    if (sz == 0)
        return 0;

    if (sz == 1)
        return nums[0];

    int noHead = helper(nums, 1, sz - 1);
    int noTail = helper(nums, 0, sz - 2);
    return max(noHead, noTail);
}

int HouseRobberII::helper(vector<int> &nums, int a, int b) {
    int sz = b - a + 1;
    vector<int> dp(sz, 0);
    dp[0] = nums[a];
    dp[1] = max(nums[a], nums[a + 1]);

    for (int i = 2; i < sz; i++)
        dp[i] = max(dp[i - 2] + nums[a + i], dp[i - 1]);

    return dp[sz - 1];
}
