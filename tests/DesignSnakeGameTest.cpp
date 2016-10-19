#include "catch.hpp"

#include "DesignSnakeGame.hpp"

TEST_CASE("Design Snake Game") {
    SECTION("Sample test") {
        vector<pair<int, int>> food{{1, 2},
                                    {0, 1}};
        SnakeGame snake(3, 2, food);
        REQUIRE(snake.move("R") == 0);
        REQUIRE(snake.move("D") == 0);
        REQUIRE(snake.move("R") == 1);
        REQUIRE(snake.move("U") == 1);
        REQUIRE(snake.move("L") == 2);
        REQUIRE(snake.move("U") == -1);
    }
}
