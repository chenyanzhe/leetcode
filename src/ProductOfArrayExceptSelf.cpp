#include "ProductOfArrayExceptSelf.hpp"

vector<int> ProductOfArrayExceptSelf::productExceptSelf(vector<int> &nums) {
    int sz = nums.size();
    vector<int> ret(sz, 1);
    int acc = 1;

    for (int i = 1; i < sz; i++)
        ret[i] = (acc *= nums[i - 1]);

    acc = 1;

    for (int i = sz - 2; i >= 0; i--)
        ret[i] *= (acc *= nums[i + 1]);

    return ret;
}