#include "catch.hpp"

#include "CountOfSmallerNumbersAfterSelf.hpp"

TEST_CASE("Count of Smaller Numbers After Self")
{
  CountOfSmallerNumbersAfterSelf s;
  SECTION("Sample tests") {
    vector<int> nums {5, 2, 6, 1};
    vector<int> expected {2, 1, 1, 0};
    vector<int> result = s.countSmaller(nums);
    REQUIRE(result == expected);
  }
  SECTION("Duplicates") {
    vector<int> nums {2, 2, 1, 1, 0};
    vector<int> expected {3, 3, 1, 1, 0};
    vector<int> result = s.countSmaller(nums);
    REQUIRE(result == expected);
  }
}
