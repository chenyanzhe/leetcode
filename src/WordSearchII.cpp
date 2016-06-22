#include "WordSearchII.hpp"

vector<string> WordSearchII::findWords(vector<vector<char>>& board,
                                       vector<string>& words)
{
  set<string> result;
  vector<string> ret;
  int nrows = board.size();

  if (nrows == 0)
    return ret;

  int ncols = board[0].size();

  if (ncols == 0)
    return ret;

  if (words.size() == 0)
    return ret;

  for (auto& w : words)
    trie.insert(w);

  vector<vector<bool>> visited (nrows, vector<bool>(ncols, false));

  for (int i = 0; i < nrows; i++)
    for (int j = 0; j < ncols; j++)
      findWords(board, visited, i, j, "", result);

  for (auto& w : result)
    ret.push_back(w);

  return ret;
}

void WordSearchII::findWords(const vector<vector<char>>& board,
                             vector<vector<bool>>& visited,
                             int row, int col, string word,
                             set<string>& result)
{
  int nrows = board.size();
  int ncols = board[0].size();

  if (row < 0 || row >= nrows || col < 0 || col >= ncols)
    return;

  if (visited[row][col])
    return;

  word.push_back(board[row][col]);

  if (!trie.startsWith(word))
    return;

  if (trie.search(word))
    result.insert(word);

  visited[row][col] = true;
  findWords(board, visited, row + 1, col, word, result);
  findWords(board, visited, row - 1, col, word, result);
  findWords(board, visited, row, col + 1, word, result);
  findWords(board, visited, row, col - 1, word, result);
  visited[row][col] = false;
}
