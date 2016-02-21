#ifndef MAXIMUM_SUBARRAY_HPP_
#define MAXIMUM_SUBARRAY_HPP_

#include <vector>
using namespace std;

class MaximumSubarray
{
public:
  int maxSubArray(vector<int>& nums);
private:
  int maxSubArray_DynamicProgramming(vector<int>& nums);
  int maxSubArray_Array(vector<int>& nums);
};

#endif // MAXIMUM_SUBARRAY_HPP_
