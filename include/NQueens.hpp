#ifndef NQUEENS_HPP_
#define NQUEENS_HPP_

#include <vector>
#include <string>

using namespace std;

class NQueens {
public:
    vector<vector<string>> solveNQueens(int n);

private:
    void helper(vector<string> &nQueens, vector<vector<string>> &res,
                int row, int n);

    bool isValid(vector<string> &nQueens, int row, int col, int n);
};

#endif // NQUEENS_HPP_
