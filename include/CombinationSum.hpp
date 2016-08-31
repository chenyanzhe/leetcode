#ifndef COMBINATION_SUM_HPP_
#define COMBINATION_SUM_HPP_

#include <vector>

using namespace std;

class CombinationSum {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target);

private:
    void
    backtrack(vector<int> &candidates, int target, int depth, int sum, vector<int> &cur, vector<vector<int>> &result);
};

#endif // COMBINATION_SUM_HPP_
