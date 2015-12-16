#include "InvertBinaryTree.hpp"

TreeNode* InvertBinaryTree::invertTree(TreeNode* root)
{
    if (root == nullptr) return root;

    TreeNode *tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    invertTree(root->left);
    invertTree(root->right);

    return root;
}
