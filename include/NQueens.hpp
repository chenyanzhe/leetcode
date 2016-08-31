#ifndef NQUEENS_HPP_
#define NQUEENS_HPP_

#include <vector>
#include <string>

using namespace std;

class NQueens {
public:
    vector<vector<string>> solveNQueens(int n);

private:
    void backtrack(int n, int depth, vector<bool> &used, vector<int> &cur, vector<vector<string>> &result);
};

#endif // NQUEENS_HPP_
