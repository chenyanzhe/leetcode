#include "RangeSumQueryImmutable.hpp"

NumArray::NumArray(vector<int>& nums)
{
  if (nums.empty()) {
    return;
  }

  accs.resize(nums.size());
  accs[0] = nums[0];

  for (int i = 1; i < nums.size(); i++) {
    accs[i] = accs[i - 1] + nums[i];
  }
}

int NumArray::sumRange(int i, int j)
{
  return i == 0 ? accs[j] : accs[j] - accs[i - 1];
}