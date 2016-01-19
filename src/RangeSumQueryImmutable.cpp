#include "RangeSumQueryImmutable.hpp"

NumArray::NumArray(vector<int>& nums)
{
  int sz = nums.size();
  sum.resize(sz);
  int acc = 0;

  for (int i = 0; i < sz; i++) {
    acc += nums[i];
    sum[i] = acc;
  }
}

int NumArray::sumRange(int i, int j)
{
  if (i == 0) {
    return sum[j];
  } else {
    return sum[j] - sum[i - 1];
  }
}