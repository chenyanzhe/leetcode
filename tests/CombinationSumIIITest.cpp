#include "catch.hpp"

#include "CombinationSumIII.hpp"

#include <algorithm>
using namespace std;

TEST_CASE("Combination Sum III")
{
  CombinationSumIII s;
  SECTION("Sample test") {
    vector<vector<int>> expected1 {{1, 2, 4}};
    vector<vector<int>> result1 = s.combinationSum3(3, 7);
    REQUIRE(expected1.size() == result1.size());

    for (int i = 0; i < expected1.size(); i++) {
      REQUIRE_FALSE(find(result1.begin(), result1.end(),
                         expected1[i]) == result1.end());
    }

    vector<vector<int>> expected2 {{1, 2, 6}, {1, 3, 5}, {2, 3, 4}};
    vector<vector<int>> result2 = s.combinationSum3(3, 9);
    REQUIRE(expected2.size() == result2.size());

    for (int i = 0; i < expected2.size(); i++) {
      REQUIRE_FALSE(find(result2.begin(), result2.end(),
                         expected2[i]) == result2.end());
    }
  }
}
