#include "LargestRectangleInHistogram.hpp"

#include "SegmentTreeMinimumRangeQuery.hpp"

#include <algorithm>
#include <climits>
using namespace std;

int LargestRectangleInHistogram::largestRectangleArea(vector<int>& height)
{
	return largestRectangleArea(height, 0, height.size() - 1);
}

int LargestRectangleInHistogram::largestRectangleArea(vector<int>& height, int l, int r)
{
	if (l > r) return INT_MIN;
	if (l == r) return height[l];

	SegmentTreeMinimumRangeQuery s;
	s.createSegmentTree(height);

	int m = s.rangeMinimumQuery(height, l, r);
	int tmp = max(largestRectangleArea(height, l, m - 1), largestRectangleArea(height, m + 1, r));
	return max(tmp, (r - l + 1) * height[m]);
}