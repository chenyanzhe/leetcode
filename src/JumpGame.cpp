#include "JumpGame.hpp"

bool JumpGame::canJump(vector<int>& nums)
{
	if (nums.size() == 0) return false;
	if (nums.size() == 1) return true;

	int canReach = 0;

	for (int i = 0; i < nums.size(); i++) {
		if (i > canReach) break;
		canReach = (nums[i] + i > canReach) ? nums[i] + i : canReach;
	}

	return canReach >= nums.size() - 1;
}
