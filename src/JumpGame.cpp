#include "JumpGame.hpp"

bool JumpGame::canJump(vector<int>& nums)
{
  int right = 0;

  for (int i = 0; i < nums.size(); i++) {
    if (i > right)
      return false;

    right = max(i + nums[i], right);
  }

  return true;
}
