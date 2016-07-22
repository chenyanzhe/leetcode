#include "catch.hpp"

#include "MultiplyStrings.hpp"

using namespace std;

TEST_CASE("Multiply Strings") {
    MultiplyStrings s;
    SECTION("Normal tests") {
        REQUIRE(s.multiply("1", "7") == "7");
        REQUIRE(s.multiply("2", "7") == "14");
        REQUIRE(s.multiply("3", "7") == "21");
        REQUIRE(s.multiply("7", "3") == "21");
    }
    SECTION("Zero tests") {
        REQUIRE(s.multiply("0", "0") == "0");
        REQUIRE(s.multiply("0", "5") == "0");
        REQUIRE(s.multiply("0", "10") == "0");
    }
    SECTION("Hundred tests") {
        REQUIRE(s.multiply("10", "10") == "100");
        REQUIRE(s.multiply("4", "25") == "100");
    }
    SECTION("Overflow tests") {
        REQUIRE(s.multiply(to_string(ULLONG_MAX), "1") == to_string(ULLONG_MAX));
        REQUIRE(s.multiply(to_string(ULLONG_MAX),
                           to_string(ULLONG_MAX)) == "340282366920938463426481119284349108225");
        REQUIRE(s.multiply("340282366920938463426481119284349108225",
                           "340282366920938463426481119284349108225") ==
                "115792089237316195398462578067141184799968521174335529155754622898352762650625");
    }
}
