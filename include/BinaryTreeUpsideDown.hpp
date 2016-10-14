#ifndef BINARY_TREE_UPSIDE_DOWN_HPP_
#define BINARY_TREE_UPSIDE_DOWN_HPP_

#include "TreeNode.hpp"

class BinaryTreeUpsideDown {
public:
    TreeNode *upsideDownBinaryTree(TreeNode *root);

private:
    TreeNode *upsideDownBinaryTree_Recursive(TreeNode *root);

    TreeNode *upsideDownBinaryTree_Iterative(TreeNode *root);
};

#endif // BINARY_TREE_UPSIDE_DOWN_HPP_