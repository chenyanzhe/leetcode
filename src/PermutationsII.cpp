#include "PermutationsII.hpp"

vector<vector<int>> PermutationsII::permuteUnique(vector<int>& nums)
{
  vector<vector<int>> ret;
  int len = nums.size();

  if (len == 0) {
    return ret;
  }

  permute(nums, 0, len - 1, ret);
  return ret;
}

bool PermutationsII::duplicate(vector<int>& nums, int head, int tail)
{
  while (head < tail) {
    if (nums[head] == nums[tail]) {
      return true;
    }

    head++;
  }

  return false;
}

void PermutationsII::permute(vector<int>& nums, int head, int tail,
                             vector<vector<int>>& ret)
{
  if (head == tail) {
    ret.push_back(nums);
  } else {
    for (int i = head; i <= tail; i++) {
      if (!duplicate(nums, head, i)) {
        swap(nums[head], nums[i]);
        permute(nums, head + 1, tail, ret);
        swap(nums[head], nums[i]);
      }
    }
  }
}
