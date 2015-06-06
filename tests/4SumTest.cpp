#include "catch.hpp"

#include "4Sum.hpp"

TEST_CASE("4Sum") {
  Solution s;

  SECTION("Sample test") {
    vector<int> nums {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> expected {
      {-1, 0, 0, 1},
      {-2, -1, 1, 2},
      {-2, 0, 0, 2}
    };
    vector<vector<int>> results = s.fourSum(nums, target);

    REQUIRE(results.size() == 3);
    for (auto quadruplet : expected)
      REQUIRE(find(results.begin(), results.end(), quadruplet) != results.end());
  }
}
