#include "catch.hpp"

#include "CombinationSum.hpp"
#include <algorithm>
using namespace std;

TEST_CASE("Combination Sum") {
  CombinationSum s;

  SECTION("Sample test") {
    vector<int> candidates {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> expected {{7}, {2, 2, 3}};
    vector<vector<int>> result = s.combinationSum(candidates, target);

    REQUIRE(result.size() == 2);
    for (int i = 0; i < 2; i++)
      REQUIRE_FALSE(find(result.begin(), result.end(), expected[i]) == result.end());
  }

  SECTION("Normal test") {
    vector<int> candidates {8, 7, 4, 3};
    int target = 11;
    vector<vector<int>> expected {{3, 4, 4},{3, 8}, {4, 7}};
    vector<vector<int>> result = s.combinationSum(candidates, target);

    REQUIRE(result.size() == 3);
    for (int i = 0; i < 3; i++)
      REQUIRE_FALSE(find(result.begin(), result.end(), expected[i]) == result.end());
  }
}
