#include "4Sum.hpp"

#include <algorithm>
using namespace std;

vector<vector<int>> FourSum::fourSum(vector<int>& nums, int target)
{
  vector<vector<int>> ret;
  if (nums.size() < 4) return ret;

  sort(nums.begin(), nums.end());

  for (int i = 0; i < nums.size(); i++) {
    if (i > 0 && nums[i] == nums[i - 1])
      continue;

    for (int j = i + 1; j < nums.size(); j++) {
      if (j > i + 1 && nums[j] == nums[j - 1])
        continue;

      int k = j + 1;
      int h = nums.size() - 1;
      int f2 = nums[i] + nums[j];
      while (k < h) {
        int sum = f2 + nums[k] + nums[h];
        if (sum == target) {
          ret.push_back({nums[i], nums[j], nums[k], nums[h]});
          do { k++; } while (k < h && nums[k] == nums[k - 1]);
          do { h--; } while (k < h && nums[h] == nums[h + 1]);
        } else if (sum < target)
          do { k++; } while (k < h && nums[k] == nums[k - 1]);
        else
          do { h--; } while (k < h && nums[h] == nums[h + 1]);
      }
    }
  }

  return ret;
}
