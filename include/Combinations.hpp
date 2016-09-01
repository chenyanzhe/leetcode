#ifndef COMBINATIONS_HPP_
#define COMBINATIONS_HPP_

#include <vector>

using namespace std;

class Combinations {
public:
    vector<vector<int>> combine(int n, int k);

private:
    void backtrack(int n, int k, int depth, vector<int> &cur, vector<vector<int>> &result);
};

#endif // COMBINATIONS_HPP_
