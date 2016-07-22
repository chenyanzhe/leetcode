#include "catch.hpp"

#include "ReverseWordsInAString.hpp"

TEST_CASE("Reverse Words in a String") {
    ReverseWordsInAString s;
    SECTION("Sample test") {
        string str = "the sky is blue";
        s.reverseWords(str);
        REQUIRE(str == "blue is sky the");
    }
}
