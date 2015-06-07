#include "catch.hpp"

#include "LongestPalindromicSubstring.hpp"

TEST_CASE("Longest Palindromic Substring") {
  LongestPalindromicSubstring s;

  SECTION("Single element") {
    REQUIRE(s.longestPalindrome("a") == "a");
  }

  SECTION("Double elements") {
    REQUIRE(s.longestPalindrome("aa") == "aa");
  }

  SECTION("Tripple elements") {
    REQUIRE(s.longestPalindrome("aba") == "aba");
    REQUIRE(s.longestPalindrome("aab") == "aa");
    REQUIRE(s.longestPalindrome("baa") == "aa");
    REQUIRE(s.longestPalindrome("aaa") == "aaa");
  }

  SECTION("Long string") {
    REQUIRE(s.longestPalindrome("jadfabcdcbakvta") == "abcdcba");
    REQUIRE(s.longestPalindrome("jaafabcdcbakvtatv") == "abcdcba");
  }
}
