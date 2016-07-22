#ifndef PEEKING_ITERATOR_HPP_
#define PEEKING_ITERATOR_HPP_

#include <vector>

using namespace std;

class Iterator {
    vector<int> nums;
    int i;
public:
    Iterator(const vector<int> &nums);

    // Returns the next element in the iteration.
    int next();

    // Returns true if the iteration has more elements.
    bool hasNext() const;
};


class PeekingIterator : public Iterator {
private:
    int p_next;
    bool p_hasnext;
public:
    PeekingIterator(const vector<int> &nums);

    // Returns the next element in the iteration without advancing the iterator.
    int peek();

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next();

    bool hasNext() const;
};

#endif // PEEKING_ITERATOR_HPP_