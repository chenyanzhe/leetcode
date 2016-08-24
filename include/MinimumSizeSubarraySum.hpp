#ifndef MINIMUM_SIZE_SUBARRAY_SUM_HPP_
#define MINIMUM_SIZE_SUBARRAY_SUM_HPP_

#include <vector>

using namespace std;

class MinimumSizeSubarraySum {
public:
    int minSubArrayLen(int s, vector<int> &nums);

private:
    int minSubArrayLen_Linear(int s, vector<int> &nums);

    int minSubArrayLen_BinarySearch(int s, vector<int> &nums);

    int searchRight(int l, int r, int target, vector<int> &sums);
};

#endif // MINIMUM_SIZE_SUBARRAY_SUM_HPP_
