#include "PermutationsII.hpp"

#include <algorithm>
#include <utility>
using namespace std;

vector<vector<int>> PermutationsII::permuteUnique(vector<int>& nums)
{
  vector<vector<int>> result;
  sort(nums.begin(), nums.end());
  helper(nums, 0, result);
  return result;
}

void PermutationsII::helper(vector<int> nums, int begin,
                            vector<vector<int>>& result)
{
  if (begin >= nums.size()) {
    result.push_back(nums);
    return;
  }

  for (int i = begin; i < nums.size(); i++) {
    if (i != begin && nums[i] == nums[begin]) {
      continue;
    }

    swap(nums[begin], nums[i]);
    helper(nums, begin + 1, result);
  }
}
