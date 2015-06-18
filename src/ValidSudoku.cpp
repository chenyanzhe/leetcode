#include "ValidSudoku.hpp"

#include <cstring>
using namespace std;

bool ValidSudoku::isValidSudoku(vector<vector<char>>& board)
{
  int rec[10];

  // check rows
  for (int i = 0; i < 9; i++) {
    memset(rec, 0, sizeof rec);
    for (auto c : board[i]) {
      if (c != '.' && rec[c - '0'])
        return false;
      else
        rec[c - '0'] = 1;
    }
  }

  // check columns
  for (int i = 0; i < 9; i++) {
    memset(rec, 0, sizeof rec);
    for (int j = 0; j < 9; j++) {
      if (board[j][i] != '.' && rec[board[j][i] - '0'])
        return false;
      else
        rec[board[j][i] - '0'] = 1;
    }
  }

  // check boxes
  for (int i = 0; i < 9; i += 3) {
    for (int j = 0; j < 9; j+= 3) {
      memset(rec, 0, sizeof rec);
      for (int k = i; k < i + 3; k++)
        for (int h = j; h < j + 3; h++) {
          if (board[k][h] != '.' && rec[board[k][h] - '0'])
            return false;
          else
            rec[board[k][h] - '0'] = 1;
        }
    }
  }

  return true;
}
