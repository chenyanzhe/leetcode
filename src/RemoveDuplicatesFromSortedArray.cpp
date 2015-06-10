#include "RemoveDuplicatesFromSortedArray.hpp"

int RemoveDuplicatesFromSortedArray::removeDuplicates(vector<int>& nums)
{
  if (nums.size() <= 1) return nums.size();

  int p = 0; // 0 ... p are identical
  int q = 1; // q is next new num

  for (; q < nums.size(); q++) {
    if (nums[q] != nums[p])
      nums[++p] = nums[q];
  }

  return p + 1;
}
