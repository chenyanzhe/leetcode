#include "ZigzagIterator.hpp"

ZigzagIterator::ZigzagIterator(vector<int> &v1, vector<int> &v2) : rowId(0), colIds(2, 0) {
    data.resize(2);
    data[0] = v1;
    data[1] = v2;
}

int ZigzagIterator::next() {
    if (hasNext()) {
        int ret = data[rowId][colIds[rowId]];
        colIds[rowId]++;
        rowId++;
        return ret;
    }
    return -1;
}

bool ZigzagIterator::hasNext() {
    for (int i = 0; i < data.size(); i++) {
        int rid = (rowId + i) % data.size();
        if (colIds[rid] < data[rid].size()) {
            rowId = rid;
            return true;
        }
    }
    return false;
}
