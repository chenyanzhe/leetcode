#include "catch.hpp"

#include "MaximumProductOfWordLengths.hpp"

TEST_CASE("Maximum Product of Word Lengths") {
    MaximumProductOfWordLengths s;
    SECTION("Sample test") {
        vector<string> words1{"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
        REQUIRE(s.maxProduct(words1) == 16); // "abcw" & "xtfn"
        vector<string> words2{"a", "ab", "abc", "d", "cd", "bcd", "abcd"};
        REQUIRE(s.maxProduct(words2) == 4); // "ab" & "cd"
        vector<string> words3{"a", "aa", "aaa", "aaaa"};
        REQUIRE(s.maxProduct(words3) == 0); // no such pair of words
    }
}