#include "catch.hpp"

#include "GameOfLife.hpp"

TEST_CASE("Game of Life") {
    GameOfLife s;
    SECTION("Sample test") {
        vector<vector<int>> board = {
                {1, 0, 1, 0},
                {0, 0, 1, 0},
                {0, 1, 1, 0},
                {1, 0, 0, 1}
        };
        vector<vector<int>> expected = {
                {0, 1, 0, 0},
                {0, 0, 1, 1},
                {0, 1, 1, 1},
                {0, 1, 1, 0}
        };
        s.gameOfLife(board);
        REQUIRE(board == expected);
    }
}
