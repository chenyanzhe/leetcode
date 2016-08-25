#include "catch.hpp"

#include "SmallestRectangleEnclosingBlackPixels.hpp"

TEST_CASE("Smallest Rectangle Enclosing Black Pixels") {
    SmallestRectangleEnclosingBlackPixels s;
    SECTION("Sample tests") {
        vector<vector<char>> image{{'0', '0', '1', '0'},
                                   {'0', '1', '1', '0'},
                                   {'0', '1', '0', '0'}};
        int x = 2, y = 2;
        REQUIRE(s.minArea(image, x, y) == 6);
    }
}