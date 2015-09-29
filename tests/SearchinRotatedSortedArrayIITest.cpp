#include "catch.hpp"

#include "SearchinRotatedSortedArrayII.hpp"

TEST_CASE("Search in Rotated Sorted Array II") {
	SearchinRotatedSortedArrayII s;

	SECTION("Sample test") {
		vector<int> nums {4, 5, 6, 7, 0, 1, 1, 2};

		REQUIRE(s.search(nums, 1));
		REQUIRE_FALSE(s.search(nums, 3));
	}

	SECTION("No duplicates") {
		vector<int> nums1 {4, 5, 6, 7, 0, 1, 2};

		REQUIRE(s.search(nums1, 1));
		REQUIRE_FALSE(s.search(nums1, 3));

		vector<int> nums2 {5, 1, 3};

		REQUIRE(s.search(nums2, 3));
	}

	SECTION("Already sorted") {
		vector<int> nums {0, 1, 1, 2, 4, 5, 6, 7};

		REQUIRE(s.search(nums, 1));
		REQUIRE_FALSE(s.search(nums, 3));
	}

	SECTION("Pivot at duplicate") {
		vector<int> nums {1, 1, 3, 1};

		REQUIRE(s.search(nums, 1));
		REQUIRE(s.search(nums, 3));
	}
}