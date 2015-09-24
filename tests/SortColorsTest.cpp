#include "catch.hpp"

#include "SortColors.hpp"

TEST_CASE("Sort Colors") {
	SortColors s;

	SECTION("Sample test") {
		vector<int> nums {0, 1, 1, 0, 2, 1, 0};
		vector<int> expected {0, 0, 0, 1, 1, 1, 2};
		s.sortColors(nums);
		REQUIRE(nums == expected);
	}
}