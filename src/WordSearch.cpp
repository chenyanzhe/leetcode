#include "WordSearch.hpp"

bool WordSearch::exist(vector<vector<char>>& board, string word)
{
  int M = board.size(), N = board[0].size();
  int sLen = word.size();

  if (M && N && sLen) {
    for (int i = 0; i < M; ++i)
      for (int j = 0; j < N; ++j)
        if (helper(board, i, j, word, 0, M, N, sLen))
          return true;
  }

  return false;
}

bool WordSearch::helper(vector<vector<char>>& board, int row, int col,
                        const string& word, int start, int M, int N, int sLen)
{
  char curC;
  bool res = false;

  if ((curC = board[row][col]) != word[start])
    return false;

  if (start == sLen - 1)
    return true;

  board[row][col] = '*';

  if (row > 0)
    res = helper(board, row - 1, col, word, start + 1, M, N, sLen);

  if (!res && row < M - 1)
    res = helper(board, row + 1, col, word, start + 1, M, N, sLen);

  if (!res && col > 0)
    res = helper(board, row, col - 1, word, start + 1, M, N, sLen);

  if (!res && col < N - 1)
    res = helper(board,  row, col + 1, word, start + 1, M, N, sLen);

  board[row][col] = curC;
  return res;
}