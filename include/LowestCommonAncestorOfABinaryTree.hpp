#ifndef LOWEST_COMMON_ANCESTOR_OF_A_BINARY_TREE_HPP_
#define LOWEST_COMMON_ANCESTOR_OF_A_BINARY_TREE_HPP_

#include "TreeNode.hpp"

class LowestCommonAncestorOfABinaryTree {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q);

private:
    TreeNode *lowestCommonAncestorRecursive(TreeNode *root, TreeNode *p,
                                            TreeNode *q);

    TreeNode *lowestCommonAncestorIterative(TreeNode *root, TreeNode *p,
                                            TreeNode *q);
};

#endif // LOWEST_COMMON_ANCESTOR_OF_A_BINARY_TREE_HPP_
