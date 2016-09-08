#include "catch.hpp"

#include "DesignTicTacToe.hpp"

TEST_CASE("Design Tic-Tac-Toe") {
    SECTION("Sample test") {
        TicTacToe toe(3);
        REQUIRE(toe.move(0, 0, 1) == 0);
        REQUIRE(toe.move(0, 2, 2) == 0);
        REQUIRE(toe.move(2, 2, 1) == 0);
        REQUIRE(toe.move(1, 1, 2) == 0);
        REQUIRE(toe.move(2, 0, 1) == 0);
        REQUIRE(toe.move(1, 0, 2) == 0);
        REQUIRE(toe.move(2, 1, 1) == 1);
    }
}
