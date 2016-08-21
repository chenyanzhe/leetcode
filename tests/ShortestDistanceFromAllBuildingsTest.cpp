#include "catch.hpp"

#include "ShortestDistanceFromAllBuildings.hpp"

TEST_CASE("Shortest Distance from All Buildings") {
    ShortestDistanceFromAllBuildings s;
    SECTION("Sample test") {
        vector<vector<int>> grid{
                {1, 0, 2, 0, 1},
                {0, 0, 0, 0, 0},
                {0, 0, 1, 0, 0}
        };
        REQUIRE(s.shortestDistance(grid) == 7);
    }

    SECTION("Unreachable test") {
        vector<vector<int>> grid{
                {1, 0, 2, 2, 1},
                {0, 0, 0, 2, 2},
                {0, 0, 1, 0, 0}
        };
        REQUIRE(s.shortestDistance(grid) == -1);
    }
}
