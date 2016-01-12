#include "catch.hpp"

#include "ContainsDuplicate.hpp"

TEST_CASE("Contains Duplicate")
{
  ContainsDuplicate s;
  SECTION("Sample test") {
    vector<int> nums_1 {1, 0, -1, 0, -2, 2};
    REQUIRE(s.containsDuplicate(nums_1));
    vector<int> nums_2 {1, 0, -1, 3, -2, 2};
    REQUIRE_FALSE(s.containsDuplicate(nums_2));
  }
}
