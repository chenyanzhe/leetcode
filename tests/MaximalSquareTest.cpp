#include "catch.hpp"

#include "MaximalSquare.hpp"

TEST_CASE("Maximal Square") {
  MaximalSquare s;

  SECTION("Sample test") {
    vector<vector<char>> matrix {
      {'1', '0', '1', '0', '0'},
      {'1', '0', '1', '1', '1'},
      {'1', '1', '1', '1', '1'},
      {'1', '0', '0', '1', '0'}
    };

    REQUIRE(s.maximalSquare(matrix) == 4);
  }

  SECTION("All zeros test") {
    vector<vector<char>> matrix {
      {'0', '0', '0', '0', '0'},
      {'0', '0', '0', '0', '0'},
      {'0', '0', '0', '0', '0'},
      {'0', '0', '0', '0', '0'}
    };

    REQUIRE(s.maximalSquare(matrix) == 0);
  }

  SECTION("Normal tests") {
    vector<vector<char>> matrix1 {
      {'1', '0', '1', '1', '0'},
      {'1', '1', '1', '1', '1'},
      {'1', '1', '1', '1', '1'},
      {'1', '0', '0', '1', '0'}
    };

    REQUIRE(s.maximalSquare(matrix1) == 4);

    vector<vector<char>> matrix2 {
      {'0', '0', '0', '1'},
      {'1', '1', '0', '1'},
      {'1', '1', '1', '1'},
      {'0', '1', '1', '1'},
      {'0', '1', '1', '1'}
    };

    REQUIRE(s.maximalSquare(matrix2) == 9);
  }
}
