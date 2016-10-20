#include "MaximumSizeSubarraySumEqualsK.hpp"

#include <unordered_map>

using namespace std;

int MaximumSizeSubarraySumEqualsK::maxSubArrayLen(vector<int> &nums, int k) {
    vector<int> sums(nums.size() + 1, 0);
    for (int i = 0; i < nums.size(); i++)
        sums[i + 1] = sums[i] + nums[i];

    int ret = 0;
    unordered_map<int, int> lookup;
    lookup[0] = 0;
    for (int i = 1; i < sums.size(); i++) {
        // find x: sums[i] - x = k, that is, x = sums[i] - k
        if (lookup.find(sums[i] - k) != lookup.end()) {
            ret = max(ret, i - lookup[sums[i] - k]);
        }
        if (lookup.find(sums[i]) == lookup.end()) {
            lookup[sums[i]] = i;
        }
    }
    return ret;
}
