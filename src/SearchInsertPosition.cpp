#include "SearchInsertPosition.hpp"

int SearchInsertPosition::searchInsert(vector<int>& nums, int target)
{
  int sz = nums.size();

  if (sz == 0)
    return 0;

  int i = 0;
  int j = sz - 1;

  while (i <= j) {
    int mid = (i + j) / 2;

    if (nums[mid] == target)
      return mid;
    else if (nums[mid] < target)
      i = mid + 1;
    else
      j = mid - 1;
  }

  return i;
}
