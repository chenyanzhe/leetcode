#include "FindMinimumInRotatedSortedArray.hpp"

int FindMinimumInRotatedSortedArray::findMin(vector<int>& nums)
{
    findMin(nums, 0, nums.size() - 1);
}

int FindMinimumInRotatedSortedArray::findMin(vector<int>& nums, int begin, int end)
{
    if (nums[begin] < nums[end]) return nums[begin];

    if (begin == end) return nums[begin];
    if (begin + 1 == end) return nums[end];

    int mid = (begin + end) / 2;
    if (nums[begin] > nums[mid])
        return findMin(nums, begin, mid);
    else // nums[mid] > nums[end]
        return findMin(nums, mid, end);
}
