#include "FirstMissingPositive.hpp"

using namespace std;

int FirstMissingPositive::firstMissingPositive(vector<int> &nums) {
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        int t = nums[i];
        while (1 <= t && t <= n && nums[t - 1] != t) {
            int nt = nums[t - 1];
            nums[t - 1] = t;
            t = nt;
        }
    }

    for (int i = 0; i < n; i++) {
        if (nums[i] != i + 1)
            return i + 1;
    }

    return n + 1;
}
