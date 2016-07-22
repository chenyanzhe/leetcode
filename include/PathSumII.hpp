#ifndef PATH_SUM_II_HPP_
#define PATH_SUM_II_HPP_

#include "TreeNode.hpp"

#include <vector>

using namespace std;

class PathSumII {
public:
    vector<vector<int>> pathSum(TreeNode *root, int sum);

private:
    void pathSum(TreeNode *root, vector<int> &path, int sum,
                 vector<vector<int>> &res);
};

#endif // PATH_SUM_II_HPP_
