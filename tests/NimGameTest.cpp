#include "catch.hpp"

#include "NimGame.hpp"

TEST_CASE("Nim Game") {
    NimGame s;
    SECTION("Sample test") {
        REQUIRE_FALSE(s.canWinNim(4));
    }
}
