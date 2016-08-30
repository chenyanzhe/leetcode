#ifndef PERMUTATIONS_II_HPP_
#define PERMUTATIONS_II_HPP_

#include <vector>

using namespace std;

class PermutationsII {
public:
    vector<vector<int>> permuteUnique(vector<int> &nums);

private:
    void backtrack(vector<int> &nums, int begin, vector<bool> &used, vector<int> &cur, vector<vector<int>> &result);
};

#endif // PERMUTATIONS_II_HPP_
