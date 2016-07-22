#include "catch.hpp"

#include "CompareVersionNumbers.hpp"

TEST_CASE("Compare Version Numbers") {
    CompareVersionNumbers s;
    SECTION("Sample tests") {
        REQUIRE(s.compareVersion("0.1", "1.1") == -1);
        REQUIRE(s.compareVersion("1.1", "1.2") == -1);
        REQUIRE(s.compareVersion("1.2", "13.37") == -1);
        REQUIRE(s.compareVersion("13.37.1", "13.37.41") == -1);
        REQUIRE(s.compareVersion("12.34.3", "12.34") == 1);
        REQUIRE(s.compareVersion("01", "1") == 0);
        REQUIRE(s.compareVersion("0.1", "1.0") == -1);
        REQUIRE(s.compareVersion("1", "1.0") == 0);
        REQUIRE(s.compareVersion("0.0.0", "0") == 0);
        REQUIRE(s.compareVersion("1.0.1", "1") == 1);
    }
}
