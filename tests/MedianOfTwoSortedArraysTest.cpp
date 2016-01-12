#include "catch.hpp"

#include "MedianOfTwoSortedArrays.hpp"

TEST_CASE("Median Of Two Sorted Arrays")
{
  MedianOfTwoSortedArrays s;
  SECTION("Two nums are empty") {
    vector<int> nums1;
    vector<int> nums2;
    REQUIRE(s.findMedianSortedArrays(nums1, nums2) == 0.0);
  }
  SECTION("Two nums do not overlap (even case)") {
    vector<int> nums1 {1, 2, 3};
    vector<int> nums2 {4, 5, 6};
    REQUIRE(s.findMedianSortedArrays(nums1, nums2) == 3.5);
  }
  SECTION("Two overlapped nums (even case)") {
    vector<int> nums1 {1, 2, 7};
    vector<int> nums2 {4, 5, 6};
    REQUIRE(s.findMedianSortedArrays(nums1, nums2) == 4.5);
  }
  SECTION("Two nums do not overlap (odd case)") {
    vector<int> nums1 {1, 2};
    vector<int> nums2 {4, 5, 6};
    REQUIRE(s.findMedianSortedArrays(nums1, nums2) == 4.0);
  }
  SECTION("Two overlapped nums (odd case)") {
    vector<int> nums1 {1, 7};
    vector<int> nums2 {4, 5, 6};
    REQUIRE(s.findMedianSortedArrays(nums1, nums2) == 5.0);
  }
}
