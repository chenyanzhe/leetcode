#include "catch.hpp"

#include "SearchA2DMatrixII.hpp"

TEST_CASE("Search a 2D Matrix II") {
    SearchA2DMatrixII s;

    SECTION("Sample test") {
        vector<vector<int>> matrix {
          {1, 4, 7, 11, 15},
          {2, 5, 8, 12, 19},
          {3, 6, 9, 16, 22},
          {10, 13, 14, 17, 24},
          {18, 21, 23, 26, 30}
        };
        REQUIRE(s.searchMatrix(matrix, 5));
        REQUIRE_FALSE(s.searchMatrix(matrix, 20));
    }
}
