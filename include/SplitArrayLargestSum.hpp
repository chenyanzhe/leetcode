#ifndef SPLIT_ARRAY_LARGEST_SUM_HPP_
#define SPLIT_ARRAY_LARGEST_SUM_HPP_

#include <vector>

using namespace std;

class SplitArrayLargestSum {
public:
    int splitArray(vector<int> &nums, int m);

private:
    bool canSplit(vector<int> &nums, int m, long long bucket);
};

#endif // SPLIT_ARRAY_LARGEST_SUM_HPP_