#include "SearchForARange.hpp"

vector<int> SearchForARange::searchRange(vector<int>& nums, int target)
{
  vector<int> ret {-1, -1};

  int len = nums.size();
  if (len == 0) return ret;

  int p = searchRange(nums, 0, len - 1, target);
  if (p == -1) return ret;

  int le = p - 1;
  int l = -1;
  while ((l = searchRange(nums, 0, le, target)) != -1)
    le = l - 1;

  int rs = p + 1;
  int r = -1;
  while ((r = searchRange(nums, rs, len - 1, target)) != -1)
    rs = r + 1;

  ret[0] = le + 1;
  ret[1] = rs - 1;

  return ret;
}

int SearchForARange::searchRange(vector<int>& nums, int l, int r, int target)
{
  if (l > r) return -1;

  while (l <= r) {
    int m = (l + r) / 2;
    if (nums[m] == target) return m;
    else if (nums[m] < target) l = m + 1;
    else r = m - 1;
  }

  return -1;
}
