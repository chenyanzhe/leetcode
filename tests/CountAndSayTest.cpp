#include "catch.hpp"

#include "CountAndSay.hpp"

TEST_CASE("Count and Say") {
    CountAndSay s;
    SECTION("Sample tests") {
        REQUIRE(s.countAndSay(1) == "1");
        REQUIRE(s.countAndSay(2) == "11");
        REQUIRE(s.countAndSay(3) == "21");
        REQUIRE(s.countAndSay(4) == "1211");
        REQUIRE(s.countAndSay(5) == "111221");
    }
}
