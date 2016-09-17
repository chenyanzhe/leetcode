#ifndef SUBSETS_HPP_
#define SUBSETS_HPP_

#include <vector>

using namespace std;

class Subsets {
public:
    vector<vector<int>> subsets(vector<int> &nums);

private:
    void backtrack(vector<int> &nums, int begin, vector<int> &local, vector<vector<int>> &global);
};

#endif // SUBSETS_HPP_
