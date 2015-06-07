#include "3Sum.hpp"

#include <algorithm>
using namespace std;

vector<vector<int>> ThreeSum::threeSum(vector<int>& nums)
{
  vector<vector<int>> ret;
  if (nums.size() < 3) return ret;

  sort(nums.begin(), nums.end());

  for (int i = 0; i < nums.size(); i++) {
    if (i > 0 && nums[i] == nums[i - 1])
      continue;

    int target = -nums[i];
    int j = i + 1;
    int k = nums.size() - 1;
    while (j < k) {
      int val = nums[j] + nums[k];
      if (val == target) {
        ret.push_back({nums[i], nums[j], nums[k]});
        do { j++; } while (j < k && nums[j] == nums[j - 1]);
        do { k--; } while (j < k && nums[k] == nums[k + 1]);
      }
      else if (val < target) {
        do { j++; } while (j < k && nums[j] == nums[j - 1]);
      } else {
        do { k--; } while (j < k && nums[k] == nums[k + 1]);
      }
    }
  }

  return ret;
}
