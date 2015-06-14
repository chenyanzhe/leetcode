#include "NextPermutation.hpp"

#include <algorithm>
using namespace std;

void NextPermutation::nextPermutation(vector<int>& nums)
{
  if (nums.size() == 1) return;

  int lvs = nums.size() - 1;

  for (int i = lvs - 1; i >= 0; i--) {
    for (int j = lvs;  j > i; j--) {
      if (nums[i] < nums[j]) {
        swap(nums[i], nums[j]);
        sort(nums.begin() + i + 1, nums.end());
        return;
      }
    }
  }

  sort(nums.begin(), nums.end());
}
