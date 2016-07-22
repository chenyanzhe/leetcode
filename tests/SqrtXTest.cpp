#include "catch.hpp"

#include "SqrtX.hpp"

TEST_CASE("Sqrt X") {
    SqrtX s;
    SECTION("Sample tests") {
        for (int i = 0; i <= 10; i++)
            REQUIRE(s.mySqrt(i) == (int) sqrt(i));
    }
    SECTION("Boundary test") {
        REQUIRE(s.mySqrt(INT_MAX) == (int) sqrt(INT_MAX));
    }
}
