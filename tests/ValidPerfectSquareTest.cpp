#include "catch.hpp"

#include "ValidPerfectSquare.hpp"

TEST_CASE("Valid Perfect Square") {
    ValidPerfectSquare s;
    SECTION("Sample tests") {
        REQUIRE(s.isPerfectSquare(16));
        REQUIRE_FALSE(s.isPerfectSquare(14));
    }
}