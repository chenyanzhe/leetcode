#ifndef SUM_ROOT_TO_LEAF_NUMBERS_HPP_
#define SUM_ROOT_TO_LEAF_NUMBERS_HPP_

#include "TreeNode.hpp"

#include <vector>
using namespace std;

class SumRootToLeafNumbers {
public:
    int sumNumbers(TreeNode* root);
private:
    void dfs(vector<TreeNode *> &path, vector<vector<int>> &result, TreeNode *start);
    int getNumberVal(const vector<int> &num);
};

#endif // SUM_ROOT_TO_LEAF_NUMBERS_HPP_