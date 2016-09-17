#include "catch.hpp"

#include "PalindromePermutation.hpp"

TEST_CASE("Palindrome Permutation") {
    PalindromePermutation s;
    SECTION("Sample tests") {
        REQUIRE_FALSE(s.canPermutePalindrome("code"));
        REQUIRE(s.canPermutePalindrome("aab"));
        REQUIRE(s.canPermutePalindrome("carerac"));
    }
}
