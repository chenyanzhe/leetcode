#include "SearchInRotatedSortedArray.hpp"

int SearchInRotatedSortedArray::search(vector<int>& nums, int target)
{
  if (nums.empty()) return -1;

  return partialSearch(nums, 0, nums.size() - 1, target);
}

int SearchInRotatedSortedArray::partialSearch(vector<int>& nums, int p, int q, int target)
{
  if (p > q) return -1;

  int m = (p + q) / 2;

  if (nums[m] == target) return m;
  
  if (nums[p] > nums[q]) {
    int left = partialSearch(nums, p, m - 1, target);
    if (left != -1) return left;
    else return partialSearch(nums, m + 1, q, target);
  } else {
    if (nums[m] < target) return partialSearch(nums, m + 1, q, target);
    else return partialSearch(nums, p, m - 1, target);
  }
}