#include "catch.hpp"

#include "HouseRobber.hpp"

TEST_CASE("House Robber") {
  HouseRobber s;

  SECTION("Normal test") {
    vector<int> nums1 {1, 2, 3, 4};
    REQUIRE(s.rob(nums1) == 6);

    vector<int> nums2 {9, 1, 9, 9, 1, 9};
    REQUIRE(s.rob(nums2) == 27);
  }
}
