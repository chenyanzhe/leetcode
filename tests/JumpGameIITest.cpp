#include "catch.hpp"

#include "JumpGameII.hpp"

TEST_CASE("Jump Game II")
{
  JumpGameII s;
  SECTION("Sample tests") {
    vector<int> nums1 {2, 3, 1, 1, 4};
    REQUIRE(s.jump(nums1) == 2);
    vector<int> nums2 {1, 2};
    REQUIRE(s.jump(nums2) == 1);
  }
  SECTION("Unreachable test") {
    vector<int> nums {0, 0, 0, 0, 0};
    REQUIRE(s.jump(nums) == -1);
  }
  SECTION("Efficiency test") {
    vector<int> nums {5, 6, 4, 4, 6, 9, 4, 4, 7, 4, 4, 8, 2, 6, 8, 1, 5, 9, 6, 5, 2, 7, 9, 7, 9, 6, 9, 4, 1, 6, 8, 8, 4, 4, 2, 0, 3, 8, 5};
    REQUIRE(s.jump(nums) == 5);
  }
}
