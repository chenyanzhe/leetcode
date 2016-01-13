#include "catch.hpp"

#include "FindTheDuplicateNumber.hpp"

TEST_CASE("Find the Duplicate Number")
{
  FindTheDuplicateNumber s;
  SECTION("Sample test") {
    vector<int> nums {3, 1, 2, 3};
    REQUIRE(s.findDuplicate(nums) == 3);
  }
}
