#include "SudokuSolver.hpp"

void SudokuSolver::solveSudoku(vector<vector<char>>& board)
{
  if (board.empty() || board.size() != 9 || board[0].size() != 9)
    return;

  solveSudoku(board, 0, 0);
}

bool SudokuSolver::solveSudoku(vector<vector<char>>& board, int m, int n)
{
  if (m == 9)
    return true;

  if (n == 9)
    return solveSudoku(board, m + 1, 0);

  if (board[m][n] == '.') {
    for (int i = 1; i <= 9; i++) {
      board[m][n] = i + '0';
      if (isValid(board, m, n) && solveSudoku(board, m, n + 1))
        return true;
      else
        board[m][n] = '.';
    }
  } else
    return solveSudoku(board, m, n + 1);

  return false;
}

bool SudokuSolver::isValid(vector<vector<char>>& board, int m, int n)
{
  int t = board[m][n];

  for (int i = 0; i < 9; i++) {
    if (i != m && board[i][n] == t)
      return false;
  }

  for (int j = 0; j < 9; j++) {
    if (j != n && board[m][j] == t)
      return false;
  }

  int _m = m / 3;
  int _n = n / 3;
  for (int i = _m * 3; i < _m * 3 + 3; i++) {
    for (int j = _n * 3; j < _n * 3 + 3; j++) {
      if ((i != m || j != n) && board[i][j] == t)
        return false;
    }
  }

  return true;
}
