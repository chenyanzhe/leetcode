#include "PeekingIterator.hpp"

Iterator::Iterator(const vector<int> &nums) : nums(nums), i(0) {}

int Iterator::next() {
    return nums[i++];
}

bool Iterator::hasNext() const {
    return i + 1 <= nums.size();
}

PeekingIterator::PeekingIterator(const vector<int> &nums) : Iterator(nums) {
    p_hasnext = Iterator::hasNext();

    if (p_hasnext)
        p_next = Iterator::next();
}

int PeekingIterator::peek() {
    return p_next;
}

int PeekingIterator::next() {
    int t = p_next;
    p_hasnext = Iterator::hasNext();

    if (p_hasnext)
        p_next = Iterator::next();

    return t;
}

bool PeekingIterator::hasNext() const {
    return p_hasnext;
}