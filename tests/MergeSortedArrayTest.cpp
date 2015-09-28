#include "catch.hpp"

#include "MergeSortedArray.hpp"

TEST_CASE("Merge Sorted Array") {
	MergeSortedArray s;
	SECTION("Sample test") {
		vector<int> nums1 {1, 3, 5, 7, 0, 0, 0, 0};
		vector<int> nums2 {2, 4, 6, 8};
		vector<int> expected {1, 2, 3, 4, 5, 6, 7, 8};
		s.merge(nums1, 4, nums2, 4);
		REQUIRE(nums1 == expected);
	}
}