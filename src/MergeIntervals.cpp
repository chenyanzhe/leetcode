#include "MergeIntervals.hpp"

#include <algorithm>
using namespace std;

vector<Interval> MergeIntervals::merge(vector<Interval>& intervals)
{
  vector<Interval> res;

  if (intervals.empty())
    return res;

  sort(intervals.begin(), intervals.end(),
  [](const Interval & a, const Interval & b) -> bool {
    return a.start < b.start;
  });
  int curstart = intervals[0].start;
  int curend = intervals[0].end;

  for (int i = 1; i < intervals.size(); i++) {
    if (intervals[i].start > curend) {
      res.emplace_back(curstart, curend);
      curstart = intervals[i].start;
      curend = intervals[i].end;
    } else
      curend = max(intervals[i].end, curend);
  }

  res.emplace_back(curstart, curend);
  return res;
}
