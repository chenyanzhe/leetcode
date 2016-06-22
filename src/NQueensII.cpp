#include "NQueensII.hpp"

int NQueensII::totalNQueens(int n)
{
  int res = 0;
  vector<string> nQueens(n, string(n, '.'));
  helper(nQueens, res, 0, n);
  return res;
}

void NQueensII::helper(vector<string>& nQueens, int& res, int row, int n)
{
  if (row == n) {
    res++;
    return;
  }

  for (int col = 0; col < n; col++) {
    if (isValid(nQueens, row, col, n)) {
      nQueens[row][col] = 'Q';
      helper(nQueens, res, row + 1, n);
      nQueens[row][col] = '.';
    }
  }
}

bool NQueensII::isValid(vector<string>& nQueens, int row, int col, int n)
{
  // check if the column had a queen before.
  for (int i = 0; i < row; i++) {
    if (nQueens[i][col] == 'Q')
      return false;
  }

  // check if the diagonals had a queen before.
  for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
    if (nQueens[i][j] == 'Q')
      return false;
  }

  for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
    if (nQueens[i][j] == 'Q')
      return false;
  }

  return true;
}