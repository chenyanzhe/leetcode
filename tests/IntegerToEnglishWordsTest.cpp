#include "catch.hpp"

#include "IntegerToEnglishWords.hpp"

TEST_CASE("Integer to English Words") {
    IntegerToEnglishWords s;
    SECTION("Sample test") {
        REQUIRE(s.numberToWords(1) == "One");
    }
}
