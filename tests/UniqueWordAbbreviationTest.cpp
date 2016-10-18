#include "catch.hpp"

#include "UniqueWordAbbreviation.hpp"

TEST_CASE("Unique Word Abbreviation") {
    SECTION("Sample test") {
        vector<string> dict{"deer", "door", "cake", "card"};
        ValidWordAbbr s(dict);
        REQUIRE_FALSE(s.isUnique("dear"));
        REQUIRE(s.isUnique("cart"));
        REQUIRE_FALSE(s.isUnique("cane"));
        REQUIRE(s.isUnique("make"));
    }
}
