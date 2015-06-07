#include "catch.hpp"

#include "StringToInteger.hpp"

TEST_CASE("String To Integer") {
  StringToInteger s;

  SECTION("Normal tests") {
    REQUIRE(s.myAtoi("1") == 1);
    REQUIRE(s.myAtoi("378") == 378);
    REQUIRE(s.myAtoi("-239") == -239);
    REQUIRE(s.myAtoi("+832") == 832);
  }

  SECTION("Boundary tests") {
    REQUIRE(s.myAtoi("-2147483648") == -2147483648);
    REQUIRE(s.myAtoi("-2147483649") == -2147483648);
    REQUIRE(s.myAtoi("2147483647") == 2147483647);
    REQUIRE(s.myAtoi("2147483648") == 2147483647);
  }

  SECTION("Format tests") {
    REQUIRE(s.myAtoi("asdfasf") == 0);
    REQUIRE(s.myAtoi("--124") == 0);
    REQUIRE(s.myAtoi("++4") == 0);
    REQUIRE(s.myAtoi("    +110?_+120__") == 110);
  }
}
