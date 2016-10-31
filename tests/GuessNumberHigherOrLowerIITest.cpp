#include "catch.hpp"

#include "GuessNumberHigherOrLowerII.hpp"

TEST_CASE("Guess Number Higher or Lower II") {
    GuessNumberHigherOrLowerII s;
    SECTION("Sample test") {
        REQUIRE(s.getMoneyAmount(1) == 0);
    }
}
