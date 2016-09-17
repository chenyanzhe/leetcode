#ifndef SUBSETS_II_HPP_
#define SUBSETS_II_HPP_

#include <vector>

using namespace std;

class SubsetsII {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums);

private:
    void
    backtrack(vector<int> &nums, int begin, vector<bool> &visited, vector<int> &local, vector<vector<int>> &global);
};

#endif // SUBSETS_II_HPP_
