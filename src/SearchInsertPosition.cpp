#include "SearchInsertPosition.hpp"

int SearchInsertPosition::searchInsert(vector<int>& nums, int target)
{
  if (nums.empty()) return 0;

  int l = 0;
  int r = nums.size() - 1;

  while (l <= r) {
    int m = (l + r) / 2;
    if (nums[m] == target)
      return m;
    else if (nums[m] < target)
      l = m + 1;
    else
      r = m - 1;
  }

  if (l == 0) return l;
  if (r == nums.size() - 1) return r + 1;

  return l;
}
