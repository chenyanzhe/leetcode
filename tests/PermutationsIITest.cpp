#include "catch.hpp"

#include "PermutationsII.hpp"
#include <algorithm>
using namespace std;

TEST_CASE("Permutations II") {
  PermutationsII s;

  SECTION("Sample test") {
    vector<int> nums {1, 2, 3};
    vector<vector<int>> expected {
      {1, 2, 3}, {1, 3, 2}, {2, 1, 3},
      {2, 3, 1}, {3, 1, 2}, {3, 2, 1}
    };
    vector<vector<int>> result = s.permuteUnique(nums);
    REQUIRE(result.size() == 6);
    for (int i = 0; i < 6; i++)
      REQUIRE_FALSE(find(expected.begin(), expected.end(), result[i]) == expected.end());
  }
  
  SECTION("Duplicate elements") {
    vector<int> nums {1, 1, 2};
    vector<vector<int>> expected {
      {1, 1, 2}, {1, 2, 1}, {2, 1, 1}
    };
    vector<vector<int>> result = s.permuteUnique(nums);
    REQUIRE(result.size() == 3);
    for (int i = 0; i < 3; i++)
      REQUIRE_FALSE(find(expected.begin(), expected.end(), result[i]) == expected.end());
  }
}

