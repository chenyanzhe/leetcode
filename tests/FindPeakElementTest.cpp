#include "catch.hpp"

#include "FindPeakElement.hpp"

TEST_CASE("Find Peak Element")
{
  FindPeakElement s;
  SECTION("Sample test") {
    vector<int> nums {1, 2, 3, 1};
    REQUIRE(s.findPeakElement(nums) == 2);
  }
}
