#include "catch.hpp"

#include "RangeSumQuery2DImmutable.hpp"

TEST_CASE("Range Sum Query 2D - Immutable") {
    SECTION("Sample test") {
        vector<vector<int>> matrix{
                {3, 0, 1, 4, 2},
                {5, 6, 3, 2, 1},
                {1, 2, 0, 1, 5},
                {4, 1, 0, 1, 7},
                {1, 0, 3, 0, 5}
        };
        NumMatrix numMatrix(matrix);
        REQUIRE(numMatrix.sumRegion(2, 1, 4, 3) == 8);
        REQUIRE(numMatrix.sumRegion(1, 1, 2, 2) == 11);
        REQUIRE(numMatrix.sumRegion(1, 2, 2, 4) == 12);
    }
}
