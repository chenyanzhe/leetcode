#include "catch.hpp"

#include "FirstUniqueCharacterInAString.hpp"

TEST_CASE("First Unique Character in a String") {
    FirstUniqueCharacterInAString s;
    SECTION("Sample test") {
        REQUIRE(s.firstUniqChar("leetcode") == 0);
        REQUIRE(s.firstUniqChar("loveleetcode") == 2);
    }
}
