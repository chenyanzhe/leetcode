#include "SortColors.hpp"

void SortColors::sortColors(vector<int>& nums)
{
  int two = nums.size() - 1, zero = 0;

  for (int i = 0; i <= two; i++) {
    while (nums[i] == 2 && i < two) {
      swap(nums[i], nums[two--]);
    }

    while (nums[i] == 0 && i > zero) {
      swap(nums[i], nums[zero++]);
    }
  }
}
