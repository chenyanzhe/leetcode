#include "catch.hpp"

#include "EliminationGame.hpp"

TEST_CASE("Elimination Game") {
    EliminationGame s;
    SECTION("Sample test") {
        REQUIRE(s.lastRemaining(9) == 6);
    }
}