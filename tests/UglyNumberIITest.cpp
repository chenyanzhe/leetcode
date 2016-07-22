#include "catch.hpp"

#include "UglyNumberII.hpp"

TEST_CASE("Ugly Number II") {
    UglyNumberII s;
    SECTION("Sample test") {
        REQUIRE(s.nthUglyNumber(10) == 12);
    }
}
