#ifndef FLATTEN_NESTED_LIST_ITERATOR_HPP_
#define FLATTEN_NESTED_LIST_ITERATOR_HPP_

#include <vector>
#include <queue>

using namespace std;

class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList);

    int next();

    bool hasNext();

private:
    deque<NestedInteger> stream;
};

#endif // FLATTEN_NESTED_LIST_ITERATOR_HPP_