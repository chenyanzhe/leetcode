#include "WordSearchII.hpp"

vector<string> WordSearchII::findWords(vector<vector<char>> &board, vector<string> &words) {
    vector<string> result;
    string cur;

    if (board.empty() || board[0].empty()) return result;
    int m = board.size(), n = board[0].size();

    vector<vector<bool>> used(m, vector<bool>(n, false));

    for (auto w : words)
        trie.insert(w);

    unordered_set<string> res;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            backtrack(board, i, j, cur, used, res);

    for (auto s : res)
        result.push_back(s);

    return result;
}

void WordSearchII::backtrack(vector<vector<char>> &board, int i, int j, string &cur, vector<vector<bool>> &used,
                             unordered_set<string> &result) {
    if (!trie.startsWith(cur))
        return;

    if (trie.search(cur))
        result.insert(cur);

    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || used[i][j])
        return;

    used[i][j] = true;
    cur.push_back(board[i][j]);

    backtrack(board, i + 1, j, cur, used, result);
    backtrack(board, i - 1, j, cur, used, result);
    backtrack(board, i, j + 1, cur, used, result);
    backtrack(board, i, j - 1, cur, used, result);

    used[i][j] = false;
    cur.pop_back();
}
