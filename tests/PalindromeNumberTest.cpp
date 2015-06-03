#include "catch.hpp"

#include "PalindromeNumber.hpp"

TEST_CASE("Palindrome Number") {
  Solution s;

  SECTION("Negative numbers are not palindrome numbers") {
    REQUIRE(s.isPalindrome(-1) == false);
    REQUIRE(s.isPalindrome(-11) == false);
    REQUIRE(s.isPalindrome(-121) == false);
  }

  SECTION("Numbers 0-9 are palindrome numbers") {
    REQUIRE(s.isPalindrome(0) == true);
    REQUIRE(s.isPalindrome(5) == true);
    REQUIRE(s.isPalindrome(9) == true);
  }

  SECTION("Normal tests") {
    REQUIRE(s.isPalindrome(11) == true);
    REQUIRE(s.isPalindrome(345) == false);
    REQUIRE(s.isPalindrome(343) == true);
    REQUIRE(s.isPalindrome(3443) == true);
    REQUIRE(s.isPalindrome(34433) == false);
  }
}
