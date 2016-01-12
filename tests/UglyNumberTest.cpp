#include "catch.hpp"

#include "UglyNumber.hpp"

TEST_CASE("Ugly Number")
{
  UglyNumber s;
  SECTION("Sample test") {
    REQUIRE(s.isUgly(6));
    REQUIRE(s.isUgly(8));
    REQUIRE_FALSE(s.isUgly(14));
  }
}
