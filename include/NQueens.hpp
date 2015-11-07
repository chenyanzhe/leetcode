#ifndef NQUEENS_HPP_
#define NQUEENS_HPP_

#include <vector>
#include <string>
using namespace std;

class NQueens {
public:
  vector<vector<string>> solveNQueens(int n);
private:
  int n;
  void helper(vector<int>& locs, int r, vector<vector<string>>& result);
  bool legal(vector<int>& locs, int r);
};

#endif // NQUEENS_HPP_
