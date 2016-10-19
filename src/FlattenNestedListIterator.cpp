#include "FlattenNestedListIterator.hpp"

// TODO: Implement the NestedInteger class

NestedIterator::NestedIterator(vector<NestedInteger> &nestedList) {
    for (auto &ni : nestedList)
        stream.push_back(ni);
}

int NestedIterator::next() {
    if (hasNext()) {
        int ret = stream.front().getInteger();
        stream.pop_front();
        return ret;
    }
    return -1;
}

bool NestedIterator::hasNext() {
    while (!stream.empty() && !stream.front().isInteger()) {
        auto t = stream.front().getList();
        stream.pop_front();
        for (int i = t.size() - 1; i >= 0; i--)
            stream.push_front(t[i]);
    }
    return !stream.empty();
}
