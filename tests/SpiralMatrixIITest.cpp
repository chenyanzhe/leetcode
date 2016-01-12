#include "catch.hpp"

#include "SpiralMatrixII.hpp"

#include <algorithm>
using namespace std;

TEST_CASE("Spiral Matrix II")
{
  SpiralMatrixII s;
  SECTION("Sample test") {
    vector<vector<int>> expected {
      {1, 2, 3},
      {8, 9, 4},
      {7, 6, 5}
    };
    REQUIRE(s.generateMatrix(3) == expected);
  }
}
