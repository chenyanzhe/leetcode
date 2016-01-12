#ifndef VALID_SUDOKU_HPP_
#define VALID_SUDOKU_HPP_

#include <vector>
using namespace std;

class ValidSudoku
{
public:
  bool isValidSudoku(vector<vector<char>>& board);
private:
  bool check(char ch, bool used[9]);
};

#endif // VALID_SUDOKU_HPP_
