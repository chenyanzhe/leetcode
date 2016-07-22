#include "catch.hpp"

#include "RotateImage.hpp"

TEST_CASE("Rotate Image") {
    RotateImage s;
    SECTION("Normal test") {
        vector<vector<int>> matrix{
                {1,  2,  3,  4},
                {5,  6,  7,  8},
                {9,  10, 11, 12},
                {13, 14, 15, 16}
        };
        vector<vector<int>> expected{
                {13, 9,  5, 1},
                {14, 10, 6, 2},
                {15, 11, 7, 3},
                {16, 12, 8, 4}
        };
        s.rotate(matrix);
        REQUIRE(matrix == expected);
    }
}
