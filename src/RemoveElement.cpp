#include "RemoveElement.hpp"

int RemoveElement::removeElement(vector<int>& nums, int val)
{
  if (nums.empty()) return 0;

  int p = 0; // 0 .. p - 1 are valid elements
  int q = 0; // q is the next unchecked element
  for (; q < nums.size(); q++) {
    if (nums[q] != val)
      nums[p++] = nums[q];
  }
  return p;
}
