#include "catch.hpp"

#include "MinimumPathSum.hpp"

TEST_CASE("Minimum Path Sum") {
  MinimumPathSum s;

  SECTION("Normal test") {
    vector<vector<int>> grid {
      {1, 2, 2, 1},
      {1, 1, 1, 2},
      {1, 2, 1, 1},
    };

    REQUIRE(s.minPathSum(grid) == 6);
  }

  SECTION("1 x 1 test") {
    vector<vector<int>> grid { { 9 } };
    REQUIRE(s.minPathSum(grid) == 9);
  }

  SECTION("2 x 2 test") {
    vector<vector<int>> grid {
      {1, 1},
      {2, 2}
    };
    REQUIRE(s.minPathSum(grid) == 4);
  }
}
