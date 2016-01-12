#include "catch.hpp"

#include "ContainsDuplicateII.hpp"

TEST_CASE("Contains Duplicate II")
{
  ContainsDuplicateII s;
  SECTION("Sample test") {
    vector<int> nums {1, 0, -1, 0, -2, 2};
    REQUIRE_FALSE(s.containsNearbyDuplicate(nums, 1));
    REQUIRE(s.containsNearbyDuplicate(nums, 2));
  }
}
