#ifndef COMBINATION_SUM_II_HPP_
#define COMBINATION_SUM_II_HPP_

#include <vector>

using namespace std;

class CombinationSumII {
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target);

private:
    void helper(vector<int> &candidates, int target, vector<vector<int>> &res,
                vector<int> &comb, int begin);
};

#endif // COMBINATION_SUM_II_HPP_
