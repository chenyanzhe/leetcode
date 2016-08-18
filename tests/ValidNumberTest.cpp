#include "catch.hpp"

#include "ValidNumber.hpp"

TEST_CASE("Valid Number") {
    ValidNumber s;
    SECTION("Sample tests") {
        REQUIRE(s.isNumber("0"));
        REQUIRE(s.isNumber(" 0.1 "));
        REQUIRE_FALSE(s.isNumber("abc"));
        REQUIRE_FALSE(s.isNumber("1 a"));
        REQUIRE(s.isNumber("2e10"));
        REQUIRE_FALSE(s.isNumber(" "));
    }
}
