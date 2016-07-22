#ifndef PERMUTATIONS_II_HPP_
#define PERMUTATIONS_II_HPP_

#include <vector>

using namespace std;

class PermutationsII {
public:
    vector<vector<int>> permuteUnique(vector<int> &nums);

private:
    void helper(vector<int> nums, int begin, vector<vector<int>> &result);
};

#endif // PERMUTATIONS_II_HPP_
