#include "catch.hpp"

#include "FactorialTrailingZeroes.hpp"

TEST_CASE("Factorial Trailing Zeroes")
{
  FactorialTrailingZeroes s;
  SECTION("Sample test") {
    REQUIRE(s.trailingZeroes(5) == 1);
  }
}
