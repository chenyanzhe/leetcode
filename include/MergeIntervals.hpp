#ifndef MERGE_INTERVALS_HPP_
#define MERGE_INTERVALS_HPP_

#include <vector>

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

class MergeIntervals {
public:
    vector<Interval> merge(vector<Interval> &intervals);
};

#endif // MERGE_INTERVALS_HPP_
