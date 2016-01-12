#ifndef SUDOKU_SOLVER_HPP_
#define SUDOKU_SOLVER_HPP_

#include <vector>
using namespace std;

class SudokuSolver
{
public:
  void solveSudoku(vector<vector<char>>& board);
private:
  bool solveSudoku(vector<vector<char>>& board, int m, int n);
  bool isValid(vector<vector<char>>& board, int m, int n);
};

#endif // SUDOKU_SOLVER_HPP_
