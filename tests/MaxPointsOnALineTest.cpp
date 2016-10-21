#include "catch.hpp"

#include "MaxPointsOnALine.hpp"

TEST_CASE("Max Points on a Line") {
    MaxPointsOnALine s;
    SECTION("Sample tests") {
        vector<Point> points{{0, 0},
                             {1, 0},
                             {1, 1},
                             {0, 2},
                             {2, 2}};
        REQUIRE(s.maxPoints(points) == 3);
    }
}
