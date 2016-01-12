#include "FindPeakElement.hpp"

int FindPeakElement::findPeakElement(vector<int>& nums)
{
  if (nums.empty()) {
    return -1;
  }

  return findPeakElement(nums, 0, nums.size() - 1);
}

int FindPeakElement::findPeakElement(vector<int>& nums, int begin, int end)
{
  if (begin == end) {
    return begin;
  }

  if (begin + 1 == end) {
    return nums[begin] < nums[end] ? end : begin;
  }

  // if nums[begin:end] does not contain *real* peak
  // case 1. strict increasing or decreasing order
  // case 2. forms a big "V"
  if (nums[begin] > nums[begin + 1]) {
    return begin;
  }

  if (nums[end] > nums[end - 1]) {
    return end;
  }

  int mid = (begin + end) / 2;

  if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
    return mid;
  }

  if (nums[mid] > nums[mid - 1]) {
    return findPeakElement(nums, mid + 1, end);
  } else {
    return findPeakElement(nums, begin, mid - 1);
  }
}
