#include "catch.hpp"

#include "EditDistance.hpp"

TEST_CASE("Edit Distance") {
  EditDistance s;

  SECTION("Normal tests") {
    REQUIRE(s.minDistance("test", "fast") == 2);
    REQUIRE(s.minDistance("distance", "distance") == 0);
  }
}
