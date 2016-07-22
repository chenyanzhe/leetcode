#include "catch.hpp"

#include "DivideTwoIntegers.hpp"

TEST_CASE("Divide Two Integers") {
    DivideTwoIntegers s;
    SECTION("Normal tests") {
        REQUIRE(s.divide(9, 5) == (9 / 5));
        REQUIRE(s.divide(10, 5) == (10 / 5));
        REQUIRE(s.divide(11, 5) == (11 / 5));
        REQUIRE(s.divide(-9, 5) == (-9 / 5));
        REQUIRE(s.divide(10, -5) == (10 / -5));
        REQUIRE(s.divide(-11, -5) == (-11 / -5));
    }
    SECTION("Zero tests") {
        REQUIRE(s.divide(5, 0) == INT_MAX);
        REQUIRE(s.divide(0, 5) == (0 / 5));
        REQUIRE(s.divide(0, 0) == INT_MAX);
    }
    SECTION("Boundary tests") {
        REQUIRE(s.divide(INT_MAX, 1) == INT_MAX);
        REQUIRE(s.divide(INT_MAX, -1) == -INT_MAX);
        REQUIRE(s.divide(1, INT_MAX) == 0);
        REQUIRE(s.divide(1, -INT_MAX) == 0);
        REQUIRE(s.divide(INT_MIN, 1) == INT_MIN);
        REQUIRE(s.divide(INT_MIN, -1) == INT_MAX);
        REQUIRE(s.divide(1, INT_MIN) == 0);
        REQUIRE(s.divide(-1, INT_MIN) == 0);
    }
    SECTION("Speed tests") {
        REQUIRE(s.divide(INT_MAX, 2) == (INT_MAX / 2));
        REQUIRE(s.divide(INT_MAX, -2) == -(INT_MAX / 2));
        REQUIRE(s.divide(INT_MIN, 2) == (INT_MIN / 2));
        REQUIRE(s.divide(INT_MIN, -2) == (INT_MIN / -2));
    }
}
