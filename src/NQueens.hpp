#ifndef NQUEENS_HPP_
#define NQUEENS_HPP_

#include <vector>
using namespace std;

class NQueens {
public:
  vector<vector<string>> solveNQueens(int n);
private:
  void helper(int n, vector<int>& locs, int r);
  bool legal(int n, vector<int>& locs, int r);
};

#endif // NQUEENS_HPP_
