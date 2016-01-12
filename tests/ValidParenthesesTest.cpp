#include "catch.hpp"

#include "ValidParentheses.hpp"

TEST_CASE("Valid Parentheses")
{
  ValidParentheses s;
  SECTION("Sample tests") {
    REQUIRE(s.isValid("()"));
    REQUIRE(s.isValid("()[]{}"));
    REQUIRE_FALSE(s.isValid("(]"));
    REQUIRE_FALSE(s.isValid("([)]"));
  }
  SECTION("Empty string") {
    REQUIRE(s.isValid(""));
  }
}
