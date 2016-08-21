#include "catch.hpp"

#include "WallsAndGates.hpp"

TEST_CASE("Walls and Gates") {
    WallsAndGates s;
    const int INF = 2147483647;
    SECTION("Sample test") {
        vector<vector<int>> rooms{
                {INF, -1,  0,   INF},
                {INF, INF, INF, -1},
                {INF, -1,  INF, -1},
                {0,   -1,  INF, INF}
        };

        vector<vector<int>> expected{
                {3, -1, 0, 1},
                {2, 2,  1, -1},
                {1, -1, 2, -1},
                {0, -1, 3, 4}
        };

        s.wallsAndGates(rooms);
        REQUIRE(rooms == expected);
    }

    SECTION("Unreachable test") {
        vector<vector<int>> rooms{
                {INF, -1,  0,   INF},
                {INF, INF, INF, -1},
                {INF, -1,  -1,  -1},
                {0,   -1,  INF, INF}
        };

        vector<vector<int>> expected{
                {3, -1, 0,   1},
                {2, 2,  1,   -1},
                {1, -1, -1,  -1},
                {0, -1, INF, INF}
        };

        s.wallsAndGates(rooms);
        REQUIRE(rooms == expected);
    }
}
