#include "catch.hpp"

#include "LongestValidParentheses.hpp"

TEST_CASE("Longest Valid Parentheses") {
  LongestValidParentheses s;

  SECTION("Sample tests") {
    string str1 = "(()";
    REQUIRE(s.longestValidParentheses(str1) == 2);

    string str2 = ")()())";
    REQUIRE(s.longestValidParentheses(str2) == 4);
  }

  SECTION("Normal tests") {
    string str1 = "(())()";
    REQUIRE(s.longestValidParentheses(str1) == 6);

    string str2 = ")(()())";
    REQUIRE(s.longestValidParentheses(str2) == 6);
  }
}
