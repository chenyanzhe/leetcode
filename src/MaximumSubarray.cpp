#include "MaximumSubarray.hpp"

#include <algorithm>
using namespace std;

int MaximumSubarray::maxSubArray(vector<int>& nums)
{
  return maxSubArray_Array(nums);
}

int MaximumSubarray::maxSubArray_DynamicProgramming(vector<int>& nums)
{
  vector<int> dp(nums.size(), 0);
  dp[0] = nums[0];
  int max = nums[0];

  for (int i = 1; i < nums.size(); i++) {
    dp[i] = nums[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
    max = dp[i] > max ? dp[i] : max;
  }

  return max;
}

int MaximumSubarray::maxSubArray_Array(vector<int>& nums)
{
  int max = nums[0];
  int maxEnding = nums[0];

  for (int i = 1; i < nums.size(); i++) {
    maxEnding = nums[i] + (maxEnding > 0 ? maxEnding : 0);
    max = maxEnding > max ? maxEnding : max;
  }

  return max;
}

int MaximumSubarray::maxSubArray_DivideAndConquer(vector<int>& nums)
{
  return helper(nums, 0, nums.size() - 1);
}

int MaximumSubarray::helper(vector<int>& nums, int left, int right)
{
  if (right == left) {
    return nums[left];
  }

  int middle = (left + right) / 2;
  int leftans = helper(nums, left, middle);
  int rightans = helper(nums, middle + 1, right);
  int leftmax = nums[middle];
  int rightmax = nums[middle + 1];
  int temp = 0;

  for(int i = middle; i >= left; i--) {
    temp += nums[i];

    if(temp > leftmax) {
      leftmax = temp;
    }
  }

  temp = 0;

  for(int i = middle + 1; i <= right; i++) {
    temp += nums[i];

    if(temp > rightmax) {
      rightmax = temp;
    }
  }

  return max(max(leftans, rightans), leftmax + rightmax);
}