#include "catch.hpp"

#include "CombinationSumII.hpp"
#include <algorithm>
using namespace std;

TEST_CASE("Combination Sum II") {
  CombinationSumII s;

  SECTION("Sample test") {
    vector<int> candidates {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> expected {{1, 7}, {1, 2, 5}, {2, 6}, {1, 1, 6}};

    vector<vector<int>> result = s.combinationSum2(candidates, target);
    REQUIRE(result.size() == 4);

    for (int i = 0; i < 4; i++)
      REQUIRE_FALSE(find(result.begin(), result.end(), expected[i]) == result.end());
  }
}
