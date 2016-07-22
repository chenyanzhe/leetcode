#ifndef NQUEENS_II_HPP_
#define NQUEENS_II_HPP_

#include <vector>
#include <string>

using namespace std;

class NQueensII {
public:
    int totalNQueens(int n);

private:
    void helper(vector<string> &nQueens, int &res, int row, int n);

    bool isValid(vector<string> &nQueens, int row, int col, int n);
};

#endif // NQUEENS_II_HPP_
