#include "RemoveDuplicatesFromSortedArray.hpp"

int RemoveDuplicatesFromSortedArray::removeDuplicates(vector<int>& nums)
{
  int j = 0;

  for (int i = 0; i < nums.size(); i++)
    if (j == 0 || nums[i] != nums[j - 1]) {
      nums[j++] = nums[i];
    }

  return j;
}
