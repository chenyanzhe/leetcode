#include "catch.hpp"

#include "PascalTriangle.hpp"

TEST_CASE("Pascal's Triangle") {
    PascalTriangle s;

    SECTION("Sample test") {
        vector<vector<int>> expected {
            {1},
            {1, 1},
            {1, 2, 1},
            {1, 3, 3, 1},
            {1, 4, 6, 4, 1}
        };

        REQUIRE(s.generate(5) == expected);
    }
}
