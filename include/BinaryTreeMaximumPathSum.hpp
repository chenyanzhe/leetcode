#ifndef BINARY_TREE_MAXIMUM_PATH_SUM_HPP_
#define BINARY_TREE_MAXIMUM_PATH_SUM_HPP_

#include "TreeNode.hpp"

class BinaryTreeMaximumPathSum {
public:
    int maxPathSum(TreeNode *root);

private:
    int maxPathDown(TreeNode *root, int &maxValue);
};

#endif // BINARY_TREE_MAXIMUM_PATH_SUM_HPP_
