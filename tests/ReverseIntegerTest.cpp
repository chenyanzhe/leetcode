#include "catch.hpp"

#include "ReverseInteger.hpp"

TEST_CASE("Reverse Integer")
{
  ReverseInteger s;
  SECTION("Sample test") {
    REQUIRE(s.reverse(123) == 321);
    REQUIRE(s.reverse(-123) == -321);
  }
  SECTION("Overflow test") {
    REQUIRE(s.reverse(-2147483648) == 0);
    REQUIRE(s.reverse(2147483647) == 0);
  }
  SECTION("Leading zeros test") {
    REQUIRE(s.reverse(1234000) == 4321);
    REQUIRE(s.reverse(-1234000) == -4321);
  }
}
