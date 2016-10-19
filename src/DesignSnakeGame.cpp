#include "DesignSnakeGame.hpp"

SnakeGame::SnakeGame(int width, int height, vector<pair<int, int>> food) : pos(0), food(food), w(width), h(height) {
    snake.emplace_back(0, 0);
    parts.emplace(0, 0);
}

int SnakeGame::move(string direction) {
    auto tail = snake.back();
    snake.pop_back();
    parts.erase(tail);

    auto next = snake.front();
    if (direction == "U")
        next.first -= 1;
    if (direction == "L")
        next.second -= 1;
    if (direction == "R")
        next.second += 1;
    if (direction == "D")
        next.first += 1;

    if (next.first < 0 || next.first >= h || next.second < 0 || next.second >= w)
        return -1; // cross the screen boundary
    if (parts.find(next) != parts.end())
        return -1; // bite its body

    snake.push_front(next);
    parts.insert(next);
    if (pos < food.size() && next == food[pos]) {
        pos++;
        parts.insert(tail);
        snake.push_back(tail);
    }
    return pos;
}
