#include "catch.hpp"

#include "MedianOfTwoSortedArrays.hpp"

TEST_CASE("Median Of Two Sorted Arrays") {
  Solution s;

  SECTION("Two nums are empty") {
    vector<int> nums1;
    vector<int> nums2;
    REQUIRE(s.findMedianSortedArrays(nums1, nums2) == 0.0);
  }

  SECTION("Two nums do not overlap") {
    vector<int> nums1 {1, 2, 3};
    vector<int> nums2 {4, 5, 6};
    REQUIRE(s.findMedianSortedArrays(nums1, nums2) == 3.5);
  }
}
