#ifndef VALIDATE_BINARY_SEARCH_TREE_HPP_
#define VALIDATE_BINARY_SEARCH_TREE_HPP_

#include "TreeNode.hpp"

class ValidateBinarySearchTree {
public:
    bool isValidBST(TreeNode *root);

public:
    bool isValidBST_PRESUC(TreeNode *root);

    bool isValidBST_INORDER(TreeNode *root);

    bool helper(TreeNode *node, TreeNode *&prev);
};

#endif // VALIDATE_BINARY_SEARCH_TREE_HPP_
