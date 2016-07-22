#include "catch.hpp"

#include "WordBreak.hpp"

TEST_CASE("Word Break") {
    WordBreak s;
    SECTION("Sample test") {
        unordered_set<string> dict{"leet", "code"};
        REQUIRE(s.wordBreak("leetcode", dict) == true);
    }
    SECTION("Prefix") {
        unordered_set<string> dict{"g", "go", "goo", "goog", "googl"};
        REQUIRE(s.wordBreak("g", dict) == true);
        REQUIRE(s.wordBreak("go", dict) == true);
        REQUIRE(s.wordBreak("gogogo", dict) == true);
        REQUIRE(s.wordBreak("gogoo", dict) == true);
        REQUIRE(s.wordBreak("google", dict) == false);
        REQUIRE(s.wordBreak("goog", dict) == true);
    }
}
