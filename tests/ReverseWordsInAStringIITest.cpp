#include "catch.hpp"

#include "ReverseWordsInAStringII.hpp"

TEST_CASE("Reverse Words in a String II") {
    ReverseWordsInAStringII s;
    SECTION("Sample test") {
        string str = "the sky is blue";
        string expected = "blue is sky the";
        s.reverseWords(str);
        REQUIRE(str == expected);
    }
    SECTION("Empty string") {
        string str = "";
        string expected = "";
        s.reverseWords(str);
        REQUIRE(str == expected);
    }
    SECTION("Single word") {
        string str = "word";
        string expected = "word";
        s.reverseWords(str);
        REQUIRE(str == expected);
    }
}
