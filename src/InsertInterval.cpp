#include "InsertInterval.hpp"

#include <algorithm>

using namespace std;

vector<Interval> InsertInterval::insert(vector<Interval> &intervals,
                                        Interval newInterval) {
    auto cmp = [](const Interval &a, const Interval &b) { return a.start < b.start; };
    sort(intervals.begin(), intervals.end(), cmp);

    auto it = lower_bound(intervals.begin(), intervals.end(), newInterval, cmp);

    if (it != intervals.begin() && newInterval.start <= (it - 1)->end)
        it--;

    int start = newInterval.start, end = newInterval.end;
    while (it != intervals.end() && !disjoint(*it, newInterval)) {
        start = min(start, it->start);
        end = max(end, it->end);
        it = intervals.erase(it);
    }
    intervals.insert(it, Interval(start, end));

    return intervals;
}

bool InsertInterval::disjoint(const Interval &a, const Interval &b)
{
    return (a.end < b.start) || (b.end < a.start);
}
