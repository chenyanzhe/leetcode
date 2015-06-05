#include "3SumClosest.hpp"

#include <algorithm>
#include <set>
#include <stdlib.h>
using namespace std;

int Solution::threeSumClosest(vector<int>& nums, int target)
{
  if (nums.size() < 3) return 0;

  vector<int> _nums(nums.begin(), nums.end());
  sort(_nums.begin(), _nums.end());

  int ret = _nums[0] + _nums[1] + _nums[2];
  int dev = abs(ret - target);

  set<int> visited;
  for (int i = 0; i < _nums.size(); i++) {
    if (visited.find(_nums[i]) != visited.end())
      continue;
    else
      visited.insert(_nums[i]);

    int v = target - _nums[i];
    int j = i + 1;
    int k = _nums.size() - 1;
    while (j < k) {
      int val = _nums[j] + _nums[k];
      if (val == v)
        return target;
      if (val < v) {
        // _nums[i] + _nums[j] + _nums[k] = _nums[i] + val < _nums[i] + v = target
        // dev = target - _nums[i] - _nums[j] - _nums[k] = v - val
        if (dev > v - val) {
          dev = v - val;
          ret = val + _nums[i];
        }
        do { j++; } while (j < k && _nums[j] == _nums[j - 1]);
      } else {
        if (dev > val - v) {
          dev = val - v;
          ret = val + _nums[i];
        }
        do { k--; } while (j < k && _nums[k] == _nums[k + 1]);
      }
    }
  }

  return ret;
}
