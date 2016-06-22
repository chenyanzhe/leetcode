#include "SearchInRotatedSortedArray.hpp"

int SearchInRotatedSortedArray::search(vector<int>& nums, int target)
{
  int l = 0;
  int h = nums.size() - 1;

  while (l <= h) {
    int m = (l + h) / 2;

    if (nums[m] == target)
      return m;

    if (nums[l] <= nums[m]) {
      // first half is sorted
      if (nums[l] <= target && target < nums[m]) {
        // target is in this half
        h = m - 1;
      } else {
        // target is in the other half
        l = m + 1;
      }
    } else {
      if (nums[m] < target && target <= nums[h])
        l = m + 1;
      else
        h = m - 1;
    }
  }

  // target not found
  return -1;
}
