#include "catch.hpp"

#include "Flatten2DVector.hpp"

TEST_CASE("Flatten 2D Vector") {
    SECTION("Sample test") {
        vector<vector<int>> vec2d {
                {1, 2},
                {3},
                {4, 5, 6}
        };
        Vector2D s(vec2d);
        REQUIRE(s.hasNext());
        REQUIRE(s.next() == 1);
        REQUIRE(s.hasNext());
        REQUIRE(s.next() == 2);
        REQUIRE(s.hasNext());
        REQUIRE(s.next() == 3);
        REQUIRE(s.hasNext());
        REQUIRE(s.next() == 4);
        REQUIRE(s.hasNext());
        REQUIRE(s.next() == 5);
        REQUIRE(s.hasNext());
        REQUIRE(s.next() == 6);
        REQUIRE_FALSE(s.hasNext());
    }
}
