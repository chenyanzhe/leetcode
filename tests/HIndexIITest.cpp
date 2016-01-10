#include "catch.hpp"

#include "HIndexII.hpp"

TEST_CASE("H-Index II") {
  HIndexII s;

  SECTION("Sample test") {
    vector<int> nums { 0, 1, 3, 5, 6 };
    REQUIRE(s.hIndex(nums) == 3);
  }
}
