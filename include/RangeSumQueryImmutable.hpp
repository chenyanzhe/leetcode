#ifndef RANGE_SUM_QUERY_IMMUTABLE_HPP_
#define RANGE_SUM_QUERY_IMMUTABLE_HPP_

#include <vector>

using namespace std;

class NumArray {
public:
    NumArray(vector<int> &nums);

    int sumRange(int i, int j);

private:
    vector<int> accs;
};

#endif // RANGE_SUM_QUERY_IMMUTABLE_HPP_
