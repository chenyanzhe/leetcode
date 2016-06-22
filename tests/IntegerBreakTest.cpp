#include "catch.hpp"

#include "IntegerBreak.hpp"

TEST_CASE("Integer Break")
{
  IntegerBreak s;
  SECTION("Sample test") {
    REQUIRE(s.integerBreak(2) == 1);
    REQUIRE(s.integerBreak(10) == 36);
  }
}
