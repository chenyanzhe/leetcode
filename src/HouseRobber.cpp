#include "HouseRobber.hpp"

using namespace std;

int HouseRobber::rob(vector<int> &nums) {
    int n = nums.size();

    if (n == 0)
        return 0;

    if (n == 1)
        return nums[0];

    if (n == 2)
        return max(nums[0], nums[1]);

    int a = nums[0];
    int b = max(nums[0], nums[1]);
    int c;

    for (int i = 2; i < n; i++) {
        c = max(b, a + nums[i]);
        a = b;
        b = c;
    }

    return c;
}
