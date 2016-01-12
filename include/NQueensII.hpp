#ifndef NQUEENS_II_HPP_
#define NQUEENS_II_HPP_

#include <vector>
using namespace std;

class NQueensII
{
public:
  int totalNQueens(int n);
private:
  int n;
  void helper(vector<int>& locs, int r, int& result);
  bool valid(vector<int>& locs, int r);
};

#endif // NQUEENS_II_HPP_
