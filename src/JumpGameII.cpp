#include "JumpGameII.hpp"

int JumpGameII::jump(vector<int>& nums)
{
  int len = nums.size();

  if (len <= 1) return 0;

  int nJumps = 0;
  int cReach = 0;
  int nReach = nums[0];

  for (int i = 0; i < len; i++) {
    if (i > cReach) {
      if (nReach <= cReach) // cannot reach
        return -1;
      cReach = nReach;
      nJumps++;
    }
    nReach = (i + nums[i] > nReach) ? i + nums[i] : nReach;
    if (nReach >= nums.size() - 1)
      return nJumps + 1;
  }

  return -1;
}
