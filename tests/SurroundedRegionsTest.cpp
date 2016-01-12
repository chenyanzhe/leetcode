#include "catch.hpp"

#include "SurroundedRegions.hpp"

TEST_CASE("Surrounded Regions")
{
  SurroundedRegions s;
  SECTION("Sample test") {
    vector<vector<char>> board {
      {'X', 'X', 'X', 'X'},
      {'X', 'O', 'O', 'X'},
      {'X', 'X', 'O', 'X'},
      {'X', 'O', 'X', 'X'}
    };
    vector<vector<char>> expected {
      {'X', 'X', 'X', 'X'},
      {'X', 'X', 'X', 'X'},
      {'X', 'X', 'X', 'X'},
      {'X', 'O', 'X', 'X'}
    };
    s.solve(board);
    REQUIRE(board == expected);
  }
}
