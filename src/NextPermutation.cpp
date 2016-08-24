#include "NextPermutation.hpp"

#include <algorithm>

using namespace std;

void NextPermutation::nextPermutation(vector<int> &nums) {
    if (nums.size() <= 1)
        return;

    int pivot = nums.size() - 1;

    while (pivot > 0 && nums[pivot - 1] >= nums[pivot])
        pivot--;

    if (pivot == 0) {
        reverse(nums.begin(), nums.end());
        return;
    } else
        pivot--;

    int change = nums.size() - 1;

    while (change > pivot && nums[change] <= nums[pivot])
        change--;

    swap(nums[change], nums[pivot]);
    reverse(nums.begin() + pivot + 1, nums.end());
}
