#ifndef BALANCED_BINARY_TREE_HPP_
#define BALANCED_BINARY_TREE_HPP_

#include "TreeNode.hpp"

class BalancedBinaryTree {
public:
    bool isBalanced(TreeNode *root);

private:
    int maxDepth(TreeNode *root);
};

#endif // BALANCED_BINARY_TREE_HPP_
