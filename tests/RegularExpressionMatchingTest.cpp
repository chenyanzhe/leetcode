#include "catch.hpp"

#include "RegularExpressionMatching.hpp"

TEST_CASE("Regular Expression Matching") {
    RegularExpressionMatching s;
    SECTION("Sample tests") {
        REQUIRE(s.isMatch("aa", "a") == false);
        REQUIRE(s.isMatch("aa", "aa") == true);
        REQUIRE(s.isMatch("aaa", "aa") == false);
        REQUIRE(s.isMatch("aaa", "a.a") == true);
        REQUIRE(s.isMatch("aa", "a*") == true);
        REQUIRE(s.isMatch("aa", ".*") == true);
        REQUIRE(s.isMatch("ab", ".*") == true);
        REQUIRE(s.isMatch("a", "ab*") == true);
        REQUIRE(s.isMatch("aab", "c*a*b") == true);
        REQUIRE(s.isMatch("", "c*c*") == true);
    }
}
