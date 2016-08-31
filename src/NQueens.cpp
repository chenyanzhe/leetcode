#include "NQueens.hpp"

#include <cstdlib>

using namespace std;

vector<vector<string>> NQueens::solveNQueens(int n) {
    vector<vector<string>> result;
    if (n <= 0) return result;

    vector<bool> used(n, false);
    vector<int> cur(n, 0);

    backtrack(n, 0, used, cur, result);

    return result;
}

void NQueens::backtrack(int n, int depth, vector<bool> &used, vector<int> &cur, vector<vector<string>> &result) {
    if (depth == n) {
        vector<string> board(n, string(n, '.'));
        for (int i = 0; i < n; i++)
            board[i][cur[i]] = 'Q';
        result.push_back(board);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (used[i]) continue;

        bool conflict = false;
        for (int j = 0; j < depth; j++) {
            if (depth - j == abs(cur[j] - i)) {
                conflict = true;
                break;
            }
        }
        if (conflict) continue;

        used[i] = true;
        cur[depth] = i;

        backtrack(n, depth + 1, used, cur, result);

        used[i] = false;
        cur[depth] = 0;
    }
}
