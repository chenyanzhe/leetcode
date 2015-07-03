#include "JumpGameII.hpp"

int JumpGameII::jump(vector<int>& nums)
{
  if (nums.empty()) return 0;

  int ret = nums.size();

  jump(nums, 0, 0, ret);

  return ret;
}

void JumpGameII::jump(vector<int>& nums, int i, int lj, int& gj)
{
  if (i > nums.size() - 1) return;

  if (i + nums[i] >= nums.size() - 1) {
    if (lj + 1 < gj) gj = lj + 1;
    return;
  }

  for (int s = 1; s <= nums[i]; s++) {
    jump(nums, i + s, lj + 1, gj);
  }
}
