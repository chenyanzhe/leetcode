#include "InorderSuccessorInBST.hpp"

TreeNode *InorderSuccessorInBST::inorderSuccessor(TreeNode *root, TreeNode *p) {
    TreeNode *ret = nullptr;

    if (p && p->right) {
        ret = p->right;
        while (ret->left)
            ret = ret->left;
        return ret;
    }

    while (root) {
        if (root == p) return ret;
        if (root->val > p->val) {
            ret = root;
            root = root->left;
        } else
            root = root->right;
    }

    return ret;
}