#ifndef COMBINATION_SUM_III_HPP_
#define COMBINATION_SUM_III_HPP_

#include <vector>

using namespace std;

class CombinationSumIII {
public:
    vector<vector<int>> combinationSum3(int k, int n);

private:
    void backtrack(int k, int target, int depth, int sum, vector<int> &cur, vector<vector<int>> &result);
};

#endif // COMBINATION_SUM_III_HPP_
