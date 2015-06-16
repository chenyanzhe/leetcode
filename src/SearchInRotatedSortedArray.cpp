#include "SearchInRotatedSortedArray.hpp"

int SearchInRotatedSortedArray::search(vector<int>& nums, int target)
{
  if (nums.empty()) return -1;

  int p = 0;
  while (p + 1 < nums.size() && nums[p] < nums[p + 1])
    p++;

  if (p + 1 == nums.size())
    return partialSearch(nums, 0, nums.size() - 1, target);

  if (target <= nums[nums.size() - 1])
    return partialSearch(nums, p + 1, nums.size() - 1, target);
  else
    return partialSearch(nums, 0, p, target);
}

int SearchInRotatedSortedArray::partialSearch(vector<int>& nums, int p, int q, int target)
{
  while (p < q) {
    int m = (p + q) / 2;
    if (nums[m] == target)
      return m;
    else if (nums[m] < target)
      p = m + 1;
    else
      q = m;
  }

  return (nums[p] == target) ? p : -1;
}
