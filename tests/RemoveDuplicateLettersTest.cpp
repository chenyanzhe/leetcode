#include "catch.hpp"

#include "RemoveDuplicateLetters.hpp"

TEST_CASE("Remove Duplicate Letters") {
    RemoveDuplicateLetters s;
    SECTION("Sample test") {
        REQUIRE(s.removeDuplicateLetters("bcabc") == "abc");
        REQUIRE(s.removeDuplicateLetters("cbacdcbc") == "acdb");
    }
}