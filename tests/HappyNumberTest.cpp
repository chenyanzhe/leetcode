#include "catch.hpp"

#include "HappyNumber.hpp"

TEST_CASE("Happy Number") {
    HappyNumber s;

    SECTION("Sample test") {
        REQUIRE(s.isHappy(19));
        REQUIRE_FALSE(s.isHappy(3));
    }
}
