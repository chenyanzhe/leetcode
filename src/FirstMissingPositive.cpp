#include "FirstMissingPositive.hpp"

#include <algorithm>
using namespace std;

int FirstMissingPositive::firstMissingPositive(vector<int>& nums)
{
  if (nums.empty()) return 1;

  sort(nums.begin(), nums.end());
  int i = 0;
  while (i < nums.size() && nums[i] <= 0)
    i++;

  if (i == nums.size() || nums[i] != 1) return 1;

  while (i + 1 < nums.size() && (nums[i] == nums[i + 1] || nums[i] + 1 == nums[i + 1]))
    i++;
  
  return nums[i] + 1;
}
