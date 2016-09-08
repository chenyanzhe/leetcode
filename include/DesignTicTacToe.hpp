#ifndef DESIGN_TIC_TAC_TOE_HPP_
#define DESIGN_TIC_TAC_TOE_HPP_

#include <vector>

using namespace std;

class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n);

    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player);

private:
    int n;
    vector<int> rows;
    vector<int> cols;
    int diagonal;
    int anti_diagonal;
};

#endif // DESIGN_TIC_TAC_TOE_HPP_