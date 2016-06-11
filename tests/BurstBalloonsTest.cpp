#include "catch.hpp"

#include "BurstBalloons.hpp"

TEST_CASE("Burst Balloons")
{
  BurstBalloons s;
  SECTION("Sample test") {
    vector<int> nums {3, 1, 5, 8};
    REQUIRE(s.maxCoins(nums) == 167);
  }
}
