#include "catch.hpp"

#include "BitwiseANDOfNumbersRange.hpp"

TEST_CASE("Bitwise AND of Numbers Range") {
    BitwiseANDOfNumbersRange s;
    SECTION("Sample test") {
        REQUIRE(s.rangeBitwiseAnd(5, 7) == 4);
    }
}
