#include "catch.hpp"

#include "JumpGameII.hpp"

TEST_CASE("Jump Game II") {
  JumpGameII s;

  SECTION("Sample test") {
    vector<int> nums {2, 3, 1, 1, 4};
    REQUIRE(s.jump(nums) == 2);
  }
}
