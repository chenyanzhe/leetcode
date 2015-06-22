#include "catch.hpp"

#include "FirstMissingPositive.hpp"

TEST_CASE("First Missing Positive") {
  FirstMissingPositive s;

  SECTION("Sample tests") {
    vector<int> nums_1 {1, 2, 0};
    REQUIRE(s.firstMissingPositive(nums_1) == 3);

    vector<int> nums_2 {3, 4, -1, 1};
    REQUIRE(s.firstMissingPositive(nums_2) == 2);
  }

  SECTION("Normal test") {
    vector<int> nums {0, 2, 2, 1, 1};
    REQUIRE(s.firstMissingPositive(nums) == 3);
  }
}
