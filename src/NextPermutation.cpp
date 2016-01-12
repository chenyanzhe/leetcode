#include "NextPermutation.hpp"

#include <algorithm>
using namespace std;

void NextPermutation::nextPermutation(vector<int>& nums)
{
  if (nums.size() <= 1) {
    return;
  }

  // step 1
  int pivot = nums.size() - 1;

  while (pivot > 0 && nums[pivot - 1] >= nums[pivot]) {
    pivot--;
  }

  // step 2.1
  if (pivot == 0) {
    reverse(nums.begin(), nums.end());
    return;
  } else {
    pivot--;
  }

  // step 2.2
  int change = nums.size() - 1;

  while (change > pivot && nums[change] <= nums[pivot]) {
    change--;
  }

  // step 3
  swap(nums[change], nums[pivot]);
  // step 4
  reverse(nums.begin() + pivot + 1, nums.end());
}
