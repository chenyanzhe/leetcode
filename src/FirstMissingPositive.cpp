#include "FirstMissingPositive.hpp"

#include <algorithm>
using namespace std;

int FirstMissingPositive::firstMissingPositive(vector<int>& nums)
{
  for (auto n : nums) {
    if (n <= 0 || n > nums.size()) {
      continue;
    }

    int r = nums[n - 1];

    while (r != n) {
      nums[n - 1] = n;

      if (r <= 0 || r > nums.size()) {
        break;
      } else {
        n = r;
        r = nums[r - 1];
      }
    }
  }

  for (int i = 0; i < nums.size(); i++)
    if (i + 1 != nums[i]) {
      return i + 1;
    }

  return nums.size() + 1;
}
