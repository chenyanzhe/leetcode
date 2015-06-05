#include "catch.hpp"

#include "3SumClosest.hpp"

TEST_CASE("3Sum Closest") {
  Solution s;

  SECTION("Sample test") {
    vector<int> nums {-1, 2, 1, -4};
    int target = 1;
    REQUIRE(s.threeSumClosest(nums, target) == 2);
  }

  SECTION("Exactly found") {
    vector<int> nums {-1, 0, 1, 2, -1, -4};
    REQUIRE(s.threeSumClosest(nums, -1) == -1);
  }
}
