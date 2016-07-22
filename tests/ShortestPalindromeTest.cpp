#include "catch.hpp"

#include "ShortestPalindrome.hpp"

TEST_CASE("Shortest Palindrome") {
    ShortestPalindrome s;
    SECTION("Sample test") {
        REQUIRE(s.shortestPalindrome("aacecaaa") == "aaacecaaa");
        REQUIRE(s.shortestPalindrome("abcd") == "dcbabcd");
    }
}
