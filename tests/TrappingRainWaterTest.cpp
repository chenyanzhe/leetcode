#include "catch.hpp"

#include "TrappingRainWater.hpp"

TEST_CASE("Trapping Rain Water") {
  TrappingRainWater s;

  SECTION("Sample test") {
    vector<int> height {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    REQUIRE(s.trap(height) == 6);
  }

  SECTION("All same height") {
    vector<int> height(8, 1);
    REQUIRE(s.trap(height) == 0);
  }

  SECTION("Single peak mountain") {
    vector<int> height {1, 2, 3, 5, 3, 1};
    REQUIRE(s.trap(height) == 0);
  }

  SECTION("Single peak two valleys mountain") {
    vector<int> height {5, 2, 1, 2, 1, 5};
    REQUIRE(s.trap(height) == 14);
  }

  SECTION("Two peaks one valley mountain") {
    vector<int> height {1, 2, 3, 5, 3, 1, 2, 1};
    REQUIRE(s.trap(height) == 1);
  }

  SECTION("Two peaks mountain with flat ground (both peaks and valleys") {
    vector<int> height {1, 2, 3, 5, 5, 3, 1, 1, 1, 2, 2, 1};
    REQUIRE(s.trap(height) == 3);
  }
}
