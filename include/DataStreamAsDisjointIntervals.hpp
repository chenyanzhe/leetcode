#ifndef DATA_STREAM_AS_DISJOINT_INTERVALS_HPP_
#define DATA_STREAM_AS_DISJOINT_INTERVALS_HPP_

#include <vector>
#include <set>

using namespace std;

struct Interval {
    int start;
    int end;

    Interval() : start(0), end(0) {}

    Interval(int s, int e) : start(s), end(e) {}

    bool operator==(const Interval &other) const {
        return start == other.start && end == other.end;
    }
};

class DataStreamAsDisjointIntervals {
public:
    DataStreamAsDisjointIntervals() {}

    void addNum(int val);

    vector<Interval> getIntervals();

private:
    void addNum_Array(int val);

    vector<Interval> getIntervals_Array();

    void addNum_BinaryTree(int val);

    vector<Interval> getIntervals_BinaryTree();

    vector<Interval> arr;

    struct OrderByStart {
        bool operator()(const Interval &a, const Interval &b) {
            return a.start < b.start;
        }
    };

    set<Interval, OrderByStart> btree;
};

#endif // DATA_STREAM_AS_DISJOINT_INTERVALS_HPP_