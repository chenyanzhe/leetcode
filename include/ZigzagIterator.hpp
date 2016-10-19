#ifndef ZIGZAG_ITERATOR_HPP_
#define ZIGZAG_ITERATOR_HPP_

#include <vector>

using namespace std;

class ZigzagIterator {
public:
    ZigzagIterator(vector<int> &v1, vector<int> &v2);

    int next();

    bool hasNext();

private:
    int rowId;
    vector<int> colIds;
    vector<vector<int>> data;
};

#endif // ZIGZAG_ITERATOR_HPP_