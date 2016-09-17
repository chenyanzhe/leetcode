#ifndef PERMUTATIONS_II_HPP_
#define PERMUTATIONS_II_HPP_

#include <vector>

using namespace std;

class PermutationsII {
public:
    vector<vector<int>> permuteUnique(vector<int> &nums);

private:
    void
    backtrack(vector<int> &nums, int begin, vector<bool> &visited, vector<int> &local, vector<vector<int>> &global);
};

#endif // PERMUTATIONS_II_HPP_
