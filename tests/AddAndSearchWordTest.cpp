#include "catch.hpp"

#include "AddAndSearchWord.hpp"

TEST_CASE("Add And Search Word") {
    WordDictionary s;

    SECTION("Sample test") {
        s.addWord("bad");
        s.addWord("dad");
        s.addWord("mad");
        REQUIRE_FALSE(s.search("pad"));
        REQUIRE(s.search("bad"));
        REQUIRE(s.search(".ad"));
        REQUIRE(s.search("b.."));
    }
}
