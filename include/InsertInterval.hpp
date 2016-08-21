#ifndef INSERT_INTERVAL_HPP_
#define INSERT_INTERVAL_HPP_

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

class InsertInterval {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval);

private:
    bool disjoint(const Interval &a, const Interval &b);
};

#endif // INSERT_INTERVAL_HPP_
