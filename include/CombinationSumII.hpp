#ifndef COMBINATION_SUM_II_HPP_
#define COMBINATION_SUM_II_HPP_

#include <vector>

using namespace std;

class CombinationSumII {
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target);

private:
    void
    backtrack(vector<int> &candidates, int target, int depth, int sum, vector<int> &cur, vector<vector<int>> &result);
};

#endif // COMBINATION_SUM_II_HPP_
