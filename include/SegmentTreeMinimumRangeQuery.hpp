#ifndef SEGMENT_TREE_MINIMUM_RANGE_QUERY_HPP_
#define SEGMENT_TREE_MINIMUM_RANGE_QUERY_HPP_

#include <vector>

using namespace std;

class SegmentTreeMinimumRangeQuery {
public:
    void createSegmentTree(const vector<int> &input);

    int rangeMinimumQuery(const vector<int> &input, int qlow, int qhigh);

private:
    int nextPowerOfTwo(int num);

    void constructMinSegmentTree(const vector<int> &input, int low, int high,
                                 int pos);

    int rangeMinimumQuery(const vector<int> &input, int low, int high, int qlow,
                          int qhigh, int pos);

private:
    vector<int> segmentTree;
};

#endif // SEGMENT_TREE_MINIMUM_RANGE_QUERY_HPP_
