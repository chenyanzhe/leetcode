#include "catch.hpp"

#include "ClimbingStairs.hpp"

TEST_CASE("Climbing Stairs")
{
  ClimbingStairs s;
  SECTION("Normal tests") {
    REQUIRE(s.climbStairs(1) == 1);
    REQUIRE(s.climbStairs(2) == 2);
    REQUIRE(s.climbStairs(3) == 3);
  }
}
