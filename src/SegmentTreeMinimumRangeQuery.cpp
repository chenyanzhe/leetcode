#include "SegmentTreeMinimumRangeQuery.hpp"

#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;

void SegmentTreeMinimumRangeQuery::createSegmentTree(const vector<int> &input)
{
	int nextPowOfTwo = nextPowerOfTwo(input.size());
    segmentTree.resize(nextPowOfTwo * 2 - 1, INT_MAX);

    constructMinSegmentTree(input, 0, input.size() - 1, 0);
}

void SegmentTreeMinimumRangeQuery::constructMinSegmentTree(const vector<int> &input, int low, int high, int pos)
{
	if (low == high) {
		segmentTree[pos] = low;
		return;
	}

	int mid = (low + high) / 2;
	constructMinSegmentTree(input, low, mid, 2 * pos + 1);
	constructMinSegmentTree(input, mid + 1, high, 2 * pos + 2);

	int l = segmentTree[2 * pos + 1];
	int r = segmentTree[2 * pos + 2];
	segmentTree[pos] = (input[l] < input[r]) ? l : r;
}

int SegmentTreeMinimumRangeQuery::rangeMinimumQuery(const vector<int> &input, int qlow, int qhigh)
{
	return rangeMinimumQuery(input, 0, input.size() - 1, qlow, qhigh, 0);
}

int SegmentTreeMinimumRangeQuery::rangeMinimumQuery(const vector<int> &input, int low, int high, int qlow, int qhigh, int pos)
{
	// total overlap
	if (qlow <= low && qhigh >= high) return segmentTree[pos];

	// non overlap
	if (qlow > high || qhigh < low) return INT_MAX;

	// partial overlap
	int mid = (low + high) / 2;
	int l = rangeMinimumQuery(input, low, mid, qlow, qhigh, 2 * pos + 1);
	int r = rangeMinimumQuery(input, mid + 1, high, qlow, qhigh, 2 * pos + 2);
	if (l == INT_MAX) return r;
	else if (r == INT_MAX) return l;
	else return (input[l] < input[r]) ? l : r;
}

int SegmentTreeMinimumRangeQuery::nextPowerOfTwo(int num)
{
	if (num == 0) return 1;

	if (num > 0 && (num & (num - 1)) == 0) return num;

	while ((num & (num - 1)) > 0)
		num = num & (num - 1);

	return num << 1;
}