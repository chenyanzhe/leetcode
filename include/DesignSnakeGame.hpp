#ifndef DESIGN_SNAKE_GAME_HPP_
#define DESIGN_SNAKE_GAME_HPP_

#include <set>
#include <queue>
#include <vector>
#include <string>
#include <utility>

using namespace std;

class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food);

    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
        @return The game's score after the move. Return -1 if game over.
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction);

private:
    set<pair<int, int>> parts;
    deque<pair<int, int>> snake;
    vector<pair<int, int>> food;
    int pos;
    int w;
    int h;
};

#endif // DESIGN_SNAKE_GAME_HPP_