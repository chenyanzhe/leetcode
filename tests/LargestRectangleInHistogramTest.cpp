#include "catch.hpp"

#include "LargestRectangleInHistogram.hpp"

TEST_CASE("Largest Rectangle in Histogram") {
	LargestRectangleInHistogram s;

	SECTION("Sample test") {
		vector<int> height {2, 1, 5, 6, 2, 3};
		REQUIRE(s.largestRectangleArea(height) == 10);
	}

	SECTION("Efficiency test") {
		vector<int> height;
		for (int i = 0; i < 20000; i++)
			height.push_back(i);
		REQUIRE(s.largestRectangleArea(height) == 100000000);
	}
}