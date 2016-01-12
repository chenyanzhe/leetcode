#include "ValidSudoku.hpp"

#include <cstring>
using namespace std;

bool ValidSudoku::isValidSudoku(vector<vector<char>>& board)
{
  bool used[9];

  // check rows and columns
  for (int i = 0; i < 9; i++) {
    memset(used, 0, sizeof used);

    for (int j = 0; j < 9; j++) {
      if (!check(board[i][j], used)) {
        return false;
      }
    }

    memset(used, 0, sizeof used);

    for (int j = 0; j < 9; j++) {
      if (!check(board[j][i], used)) {
        return false;
      }
    }
  }

  // check blocks
  for (int i = 0; i < 9; i += 3) {
    for (int j = 0; j < 9; j += 3) {
      memset(used, 0, sizeof used);

      for (int k = i; k < i + 3; k++)
        for (int h = j; h < j + 3; h++) {
          if (!check(board[k][h], used)) {
            return false;
          }
        }
    }
  }

  return true;
}

bool ValidSudoku::check(char ch, bool used[9])
{
  if (ch == '.') {
    return true;
  }

  if (used[ch - '1']) {
    return false;
  }

  return used[ch - '1'] = true;
}
