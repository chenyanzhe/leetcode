#include "catch.hpp"

#include "AddDigits.hpp"

TEST_CASE("Add Digits") {
    AddDigits s;
    SECTION("Sample test") {
        REQUIRE(s.addDigits(10) == 1);
        REQUIRE(s.addDigits(39) == 3);
    }
}
