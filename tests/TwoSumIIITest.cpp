#include "catch.hpp"

#include "TwoSumIII.hpp"

TEST_CASE("Two Sum III - Data structure design") {
    TwoSumIII s;
    SECTION("Sample test") {
        s.add(1);
        s.add(3);
        s.add(5);
        REQUIRE(s.find(4));
        REQUIRE_FALSE(s.find(7));
    }
}
