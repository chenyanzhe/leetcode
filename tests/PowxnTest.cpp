#include "catch.hpp"

#include "Powxn.hpp"
#include <climits>

TEST_CASE("Pow(x, n)") {
  Powxn s;

  SECTION("Normal tests") {
    REQUIRE(s.myPow(1.0, 0) == 1.0);
    REQUIRE(s.myPow(2.0, 2) == 4.0);
    REQUIRE(s.myPow(2.0, -2) == 0.25);
  }

  SECTION("Efficiency test") {
    REQUIRE(s.myPow(0.00001, INT_MAX) == Approx(0.0));
  }

  SECTION("Overflow handling") {
    REQUIRE(s.myPow(1.00000, INT_MIN) == 1.0);
  }
}
