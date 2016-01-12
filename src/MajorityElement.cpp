#include "MajorityElement.hpp"

int MajorityElement::majorityElement(vector<int>& nums)
{
  int result = nums[0];
  int counter = 1;

  for (int i = 1; i < nums.size(); i++) {
    counter += (nums[i] == result) ? 1 : -1;

    if (counter == 0) {
      result = nums[i];
      counter = 1;
    }
  }

  return result;
}
