#include "catch.hpp"

#include "MaximumSubarray.hpp"

TEST_CASE("Maximum Subarray")
{
  MaximumSubarray s;

  SECTION("Sample test") {
    vector<int> nums {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    REQUIRE(s.maxSubArray(nums) == 6);
  }

  SECTION("Single element") {
    vector<int> nums1 {-1};
    REQUIRE(s.maxSubArray(nums1) == -1);

    vector<int> nums2 {9};
    REQUIRE(s.maxSubArray(nums2) == 9);
  }

  SECTION("Double elements") {
    vector<int> nums1 {-1, 5};
    REQUIRE(s.maxSubArray(nums1) == 5);

    vector<int> nums2 {5, -1};
    REQUIRE(s.maxSubArray(nums2) == 5);

    vector<int> nums3 {-1, -6};
    REQUIRE(s.maxSubArray(nums3) == -1);

    vector<int> nums4 {4, 3};
    REQUIRE(s.maxSubArray(nums4) == 7);
  }
}
