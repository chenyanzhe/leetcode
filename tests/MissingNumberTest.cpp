#include "catch.hpp"

#include "MissingNumber.hpp"

TEST_CASE("Missing Number") {
  MissingNumber s;

  SECTION("Sample test") {
    vector<int> nums { 0, 1, 3 };
    REQUIRE(s.missingNumber(nums) == 2);
  }
}
