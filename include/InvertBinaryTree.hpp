#ifndef INVERT_BINARY_TREE_HPP_
#define INVERT_BINARY_TREE_HPP_

#include "TreeNode.hpp"

class InvertBinaryTree {
public:
    TreeNode *invertTree(TreeNode *root);

private:
    TreeNode *invertTreeRecursive(TreeNode *root);

    TreeNode *invertTreeIterative(TreeNode *root);
};

#endif // INVERT_BINARY_TREE_HPP_
