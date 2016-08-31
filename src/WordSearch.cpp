#include "WordSearch.hpp"

bool WordSearch::exist(vector<vector<char>> &board, string word) {
    if (board.empty() || board[0].empty())
        return false;

    int m = board.size(), n = board[0].size();
    vector<vector<bool>> used(m, vector<bool>(n, false));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (backtrack(board, word, 0, i, j, used))
                return true;

    return false;
}

bool
WordSearch::backtrack(vector<vector<char>> &board, string &word, int depth, int i, int j, vector<vector<bool>> &used) {
    if (depth == word.size())
        return true;

    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
        return false;

    if (used[i][j] || board[i][j] != word[depth])
        return false;

    used[i][j] = true;

    if (backtrack(board, word, depth + 1, i - 1, j, used) ||
        backtrack(board, word, depth + 1, i + 1, j, used) ||
        backtrack(board, word, depth + 1, i, j - 1, used) ||
        backtrack(board, word, depth + 1, i, j + 1, used))
        return true;

    used[i][j] = false;

    return false;
}