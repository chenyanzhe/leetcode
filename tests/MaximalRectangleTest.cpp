#include "catch.hpp"

#include "MaximalRectangle.hpp"

TEST_CASE("Maximal Rectangle") {
    MaximalRectangle s;
    SECTION("Sample tests") {
        vector<vector<char>> matrix1{
                {'0', '0', '1', '0'},
                {'0', '0', '0', '1'},
                {'0', '1', '1', '1'},
                {'0', '0', '1', '1'}
        };
        REQUIRE(s.maximalRectangle(matrix1) == 4);
        vector<vector<char>> matrix2{
                {'0', '1', '1', '0'},
                {'0', '1', '1', '1'},
                {'0', '1', '1', '1'},
                {'0', '0', '1', '1'}
        };
        REQUIRE(s.maximalRectangle(matrix2) == 6);
    }
    SECTION("Corner test") {
        vector<vector<char>> matrix1{
                {'0'}
        };
        REQUIRE(s.maximalRectangle(matrix1) == 0);
        vector<vector<char>> matrix2{
                {'1', '0'}
        };
        REQUIRE(s.maximalRectangle(matrix2) == 1);
        vector<vector<char>> matrix3{
                {'0', '1'},
                {'0', '1'}
        };
        REQUIRE(s.maximalRectangle(matrix3) == 2);
    }
}
