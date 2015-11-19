#include "catch.hpp"

#include "Numberof1Bits.hpp"

TEST_CASE("Number of 1 Bits") {
    Numberof1Bits s;

    SECTION("Sample test") {
        REQUIRE(s.hammingWeight(11) == 3);
    }
}
