#include "RotateArray.hpp"

#include <algorithm>

void RotateArray::rotate(vector<int>& nums, int k)
{
  k = k % nums.size();
  int m = nums.size() - k;
  int n = k;

  if (k == 0)
    return;

  int i, j;
  // reverse nums[0:m-1]
  i = 0;
  j = m - 1;

  while (i < j) {
    swap(nums[i], nums[j]);
    i++;
    j--;
  }

  // reverse nums[m:m+n-1]
  i = m;
  j = m + n - 1;

  while (i < j) {
    swap(nums[i], nums[j]);
    i++;
    j--;
  }

  // reverse nums[0:m+n-1]
  i = 0;
  j = m + n - 1;

  while (i < j) {
    swap(nums[i], nums[j]);
    i++;
    j--;
  }
}
