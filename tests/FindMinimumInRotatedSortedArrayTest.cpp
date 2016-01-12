#include "catch.hpp"

#include "FindMinimumInRotatedSortedArray.hpp"

TEST_CASE("Find Minimum in Rotated Sorted Array")
{
  FindMinimumInRotatedSortedArray s;
  SECTION("Sample test") {
    vector<int> nums {4, 5, 6, 7, 0, 1, 2};
    REQUIRE(s.findMin(nums) == 0);
  }
}
