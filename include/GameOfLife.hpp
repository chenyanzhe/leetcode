#ifndef GAME_OF_LIFE_HPP_
#define GAME_OF_LIFE_HPP_

#include <vector>

using namespace std;

class GameOfLife {
public:
    void gameOfLife(vector<vector<int>> &board);

private:
    int count(vector<vector<int>> &board, int i, int j);

    bool isLive(vector<vector<int>> &board, int i, int j);
};

#endif // GAME_OF_LIFE_HPP_