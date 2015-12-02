#include "catch.hpp"

#include "SegmentTreeMinimumRangeQuery.hpp"

TEST_CASE("Segment Tree Minimum Range Query") {
	SegmentTreeMinimumRangeQuery s;

	SECTION("Sample test") {
		vector<int> input {4, 3, 0, 2, 1, 6, -1};
		vector<int> expected {0, 1, 2, 2, 2, 2, 6};
		s.createSegmentTree(input);

		for (int i = 0; i < input.size(); i++)
			REQUIRE(s.rangeMinimumQuery(input, 0, i) == expected[i]);
	}
}
