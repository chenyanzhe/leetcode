#include "catch.hpp"

#include "StringToInteger.hpp"

TEST_CASE("String To Integer") {
  Solution s;

  SECTION("Normal tests") {
    REQUIRE(s.myAtoi("1") == 1);
  }

  SECTION("Normal tests 2") {
    REQUIRE(s.myAtoi("    010") == 10);
  }
}
