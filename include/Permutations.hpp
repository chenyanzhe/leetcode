#ifndef PERMUTATIONS_HPP_
#define PERMUTATIONS_HPP_

#include <vector>

using namespace std;

class Permutations {
public:
    vector<vector<int>> permute(vector<int> &nums);

private:
    void
    backtrack(vector<int> &nums, int begin, vector<bool> &visited, vector<int> &local, vector<vector<int>> &global);
};

#endif // PERMUTATIONS_HPP_
