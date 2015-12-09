#include "KthLargestElementInAnArray.hpp"

int KthLargestElementInAnArray::findKthLargest(vector<int>& nums, int k)
{
    return findKthLargest(nums, 0, nums.size() - 1, k);
}

int KthLargestElementInAnArray::findKthLargest(vector<int>& nums, int i, int j, int k)
{
    if (i == j) return nums[i];

    int p = partition(nums, i, j);

    if (p - i == k - 1) return nums[p];
    else if (p - i < k - 1) return findKthLargest(nums, p + 1, j, k - (p - i + 1));
    else return findKthLargest(nums, i, p - 1, k);
}

 int KthLargestElementInAnArray::partition(vector<int>& nums, int begin, int end)
 {
     int i = begin;
     for (int j = begin + 1; j <= end; j++) {
         if (nums[j] <= nums[i])
             continue;
         else {
             int temp = nums[j];
             nums[j] = nums[i+1];
             nums[i+1] = nums[i];
             nums[i] = temp;
             i++;
         }
     }
     return i;
 }
