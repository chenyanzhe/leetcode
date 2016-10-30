#include "MaximumProductSubarray.hpp"

#include <algorithm>

using namespace std;

int MaximumProductSubarray::maxProduct(vector<int> &nums) {
    if (nums.empty()) return 0;

    vector<int> a(nums.begin(), nums.end());
    vector<int> b(nums.begin(), nums.end());
    int ret = a[0];

    for (int i = 1; i < nums.size(); i++) {
        int v1 = a[i - 1] * nums[i];
        int v2 = b[i - 1] * nums[i];
        a[i] = max(a[i], max(v1, v2));
        b[i] = min(b[i], min(v1, v2));
        ret = max(ret, a[i]);
    }

    return ret;
}
