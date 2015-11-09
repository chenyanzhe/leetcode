#include "FindMinimumInRotatedSortedArrayII.hpp"

int FindMinimumInRotatedSortedArrayII::findMin(vector<int>& nums)
{
    return findMin(nums, 0, nums.size() - 1);
}

int FindMinimumInRotatedSortedArrayII::findMin(vector<int>& nums, int begin, int end)
{
    if (nums[begin] < nums[end]) return nums[begin];

    if (begin == end) return nums[begin];
    if (begin + 1 == end) return nums[end];

    int mid = (begin + end) / 2;
    if (nums[begin] < nums[mid])
        return findMin(nums, mid, end);
    else if (nums[mid] < nums[end])
        return findMin(nums, begin, mid);
    else {
        int left = findMin(nums, begin, mid);
        int right = findMin(nums, mid, end);
        return (left < right) ? left : right;
    }
}
