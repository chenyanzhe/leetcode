#ifndef MAXIMUM_SUBARRAY_HPP_
#define MAXIMUM_SUBARRAY_HPP_

#include <vector>

using namespace std;

class MaximumSubarray {
public:
    int maxSubArray(vector<int> &nums);

private:
    int maxSubArray_DynamicProgramming(vector<int> &nums);

    void maxSubArray_DivideAndConquer(vector<int> &nums, int l, int r, int &mx, int &lmx, int &rmx, int &sum);
};

#endif // MAXIMUM_SUBARRAY_HPP_
