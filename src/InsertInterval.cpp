#include "InsertInterval.hpp"

#include <algorithm>
using namespace std;

vector<Interval> InsertInterval::insert(vector<Interval>& intervals, Interval newInterval)
{
	intervals.push_back(newInterval);

	sort(intervals.begin(), intervals.end(),
		[](const Interval &a, const Interval &b) {
			return a.start < b.start;
		});

	bool changed = false;
	vector<Interval> origin = intervals;
	vector<Interval> backup;

	do {
		changed = false;
		if (origin.size() <= 1) break;
		for (int i = 0; i < origin.size() - 1; i++) {
			if (origin[i].end < origin[i+1].start)
				backup.push_back(origin[i]);
			else {
				origin[i+1].start = origin[i].start;
				origin[i+1].end = (origin[i+1].end > origin[i].end) ? origin[i+1].end : origin[i].end;
				changed = true;
			}
		}
		backup.push_back(origin[origin.size() - 1]);
		origin = backup;
		backup.clear();
	} while (changed);

	return origin;
}