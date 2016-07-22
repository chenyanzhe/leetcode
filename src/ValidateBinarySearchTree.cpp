#include "ValidateBinarySearchTree.hpp"

bool ValidateBinarySearchTree::isValidBST(TreeNode *root) {
    return isValidBST_INORDER(root);
}

bool ValidateBinarySearchTree::isValidBST_INORDER(TreeNode *root) {
    TreeNode *prev = nullptr;
    return helper(root, prev);
}

bool ValidateBinarySearchTree::helper(TreeNode *node, TreeNode *&prev) {
    if (node == nullptr)
        return true;

    if (!helper(node->left, prev))
        return false;

    if (prev != nullptr && prev->val >= node->val)
        return false;

    prev = node;
    return helper(node->right, prev);
}

bool ValidateBinarySearchTree::isValidBST_PRESUC(TreeNode *root) {
    if (root == nullptr)
        return true;

    if (root->left != nullptr) {
        // find predecessor
        TreeNode *prev = root->left;

        while (prev->right != nullptr)
            prev = prev->right;

        if (prev->val >= root->val)
            return false;
    }

    if (root->right != nullptr) {
        // find successor
        TreeNode *next = root->right;

        while (next->left != nullptr)
            next = next->left;

        if (next->val <= root->val)
            return false;
    }

    return isValidBST(root->left) && isValidBST(root->right);
}
