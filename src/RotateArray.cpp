#include "RotateArray.hpp"

void RotateArray::rotate(vector<int> &nums, int k) {
    k = k % nums.size();
    int m = nums.size() - k;
    int n = k;

    if (k == 0) return;

    int i = 0, j = m - 1;

    while (i < j)
        swap(nums[i++], nums[j--]);

    i = m, j = m + n - 1;

    while (i < j)
        swap(nums[i++], nums[j--]);

    i = 0, j = m + n - 1;

    while (i < j)
        swap(nums[i++], nums[j--]);
}
