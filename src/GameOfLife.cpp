#include "GameOfLife.hpp"

#include <iostream>

using namespace std;

void GameOfLife::gameOfLife(vector<vector<int>> &board) {
    // mark state changed from 0 to 1 to 2
    // mark state changed from 1 to 0 to 3
    int m = board.size();

    if (m == 0)
        return;

    int n = board[0].size();

    if (n == 0)
        return;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int ones = count(board, i, j);

            if (board[i][j] == 0 && ones == 3)
                board[i][j] = 2;
            else if (board[i][j] == 1 && (ones < 2 || ones > 3))
                board[i][j] = 3;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 2)
                board[i][j] = 1;

            if (board[i][j] == 3)
                board[i][j] = 0;
        }
    }
}

int GameOfLife::count(vector<vector<int>> &board, int i, int j) {
    int m = board.size();
    int n = board[0].size();
    int count = 0;

    if (i - 1 >= 0) {
        if (j - 1 >= 0)
            count += isLive(board, i - 1, j - 1) ? 1 : 0;

        if (j + 1 < n)
            count += isLive(board, i - 1, j + 1) ? 1 : 0;

        count += isLive(board, i - 1, j) ? 1 : 0;
    }

    if (i + 1 < m) {
        if (j - 1 >= 0)
            count += isLive(board, i + 1, j - 1) ? 1 : 0;

        if (j + 1 < n)
            count += isLive(board, i + 1, j + 1) ? 1 : 0;

        count += isLive(board, i + 1, j) ? 1 : 0;
    }

    if (j - 1 >= 0)
        count += isLive(board, i, j - 1) ? 1 : 0;

    if (j + 1 < n)
        count += isLive(board, i, j + 1) ? 1 : 0;

    return count;
}

bool GameOfLife::isLive(vector<vector<int>> &board, int i, int j) {
    return board[i][j] == 1 || board[i][j] == 3;
}