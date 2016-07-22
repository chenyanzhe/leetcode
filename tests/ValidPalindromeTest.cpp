#include "catch.hpp"

#include "ValidPalindrome.hpp"

TEST_CASE("Valid Palindrome") {
    ValidPalindrome s;
    SECTION("Sample test") {
        REQUIRE(s.isPalindrome("A man, a plan, a canal: Panama"));
        REQUIRE_FALSE(s.isPalindrome("race a car"));
    }
}
