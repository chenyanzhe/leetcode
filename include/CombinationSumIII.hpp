#ifndef COMBINATION_SUM_III_HPP_
#define COMBINATION_SUM_III_HPP_

#include <vector>

using namespace std;

class CombinationSumIII {
public:
    vector<vector<int>> combinationSum3(int k, int n);

private:
    void helper(int target, vector<vector<int>> &res, vector<int> &comb, int begin,
                int k);
};

#endif // COMBINATION_SUM_III_HPP_
