#include "catch.hpp"

#include "SlidingWindowMaximum.hpp"

TEST_CASE("Sliding Window Maximum")
{
  SlidingWindowMaximum s;
  SECTION("Sample test") {
    vector<int> nums {1, 3, 1, 2, 0, 5};
    vector<int> expected {3, 3, 2, 5};
    REQUIRE(s.maxSlidingWindow(nums, 3) == expected);
  }
}
