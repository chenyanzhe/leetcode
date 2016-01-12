#include "MissingNumber.hpp"

int MissingNumber::missingNumber(vector<int>& nums)
{
  int missing = nums.size();

  for (int i = 0; i < nums.size(); i++) {
    int target = nums[i];

    // place target to the right place
    while (target != i && target != nums.size()) {
      swap(nums[target], target);
    }

    if (target == nums.size()) {
      missing = i;
      nums[i] = nums.size();
    }
  }

  return missing;
}
