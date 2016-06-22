#include "RemoveDuplicatesFromSortedArrayII.hpp"

int RemoveDuplicatesFromSortedArrayII::removeDuplicates(vector<int>& nums)
{
  int K = 2;
  int j = K;

  if (nums.size() <= K)
    return nums.size();

  for (int i = K; i < nums.size(); i++)
    if (nums[j - K] != nums[i])
      nums[j++] = nums[i];

  return j;
}
