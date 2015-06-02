#include "catch.hpp"

#include "ReverseInteger.hpp"

TEST_CASE("Reverse Integer") {
  Solution s;

  SECTION("Sample test") {
    REQUIRE(s.reverse(123) == 321);
    REQUIRE(s.reverse(-123) == -321);
  }
}
