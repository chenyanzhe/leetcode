#include "DataStreamAsDisjointIntervals.hpp"

void DataStreamAsDisjointIntervals::addNum(int val) {
    // addNum_Array(val);
    addNum_BinaryTree(val);
}

vector<Interval> DataStreamAsDisjointIntervals::getIntervals() {
    // return getIntervals_Array();
    return getIntervals_BinaryTree();
}

void DataStreamAsDisjointIntervals::addNum_Array(int val) {
    auto cmp = [](const Interval &a, const Interval &b) { return a.start < b.start; };
    auto it = lower_bound(arr.begin(), arr.end(), Interval(val, val), cmp);

    if (it != arr.begin() && val <= (it - 1)->end + 1)
        it--;

    int start = val, end = val;
    while (it != arr.end() && it->start - 1 <= val && val <= it->end + 1) {
        start = min(it->start, start);
        end = max(it->end, end);
        it = arr.erase(it);
    }
    arr.insert(it, Interval(start, end));
}

vector<Interval> DataStreamAsDisjointIntervals::getIntervals_Array() {
    return arr;
}

void DataStreamAsDisjointIntervals::addNum_BinaryTree(int val) {
    auto it = btree.lower_bound(Interval(val, val));

    if (it != btree.begin() && val > (--it)->end + 1)
        it++;

    int start = val, end = val;
    while (it != btree.end() && it->start - 1 <= val && val <= it->end + 1) {
        start = min(it->start, start);
        end = max(it->end, end);
        it = btree.erase(it);
    }
    btree.insert(it, Interval(start, end));
}

vector<Interval> DataStreamAsDisjointIntervals::getIntervals_BinaryTree() {
    vector<Interval> ret;

    for (auto item : btree)
        ret.push_back(item);

    return ret;
}