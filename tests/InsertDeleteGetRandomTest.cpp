#include "catch.hpp"

#include "InsertDeleteGetRandom.hpp"

TEST_CASE("Insert Delete GetRandom O(1)") {
    RandomizedSet s;
    SECTION("Sample test") {
        REQUIRE(s.insert(0)); // {0}
        REQUIRE(s.insert(1)); // {0, 1}
        REQUIRE(s.remove(0)); // {0}
        REQUIRE(s.insert(2)); // {1, 2}
        REQUIRE(s.remove(1)); // {2}
        REQUIRE(s.getRandom() == 2);
    }
}
