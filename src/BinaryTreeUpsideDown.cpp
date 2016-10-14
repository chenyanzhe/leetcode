#include "BinaryTreeUpsideDown.hpp"

TreeNode *BinaryTreeUpsideDown::upsideDownBinaryTree(TreeNode *root) {
    return upsideDownBinaryTree_Iterative(root);
}

TreeNode *BinaryTreeUpsideDown::upsideDownBinaryTree_Recursive(TreeNode *root) {
    if (root == nullptr || root->left == nullptr)
        return root;

    TreeNode *newRoot = upsideDownBinaryTree_Recursive(root->left);

    root->left->left = root->right;
    root->left->right = root;
    root->left = root->right = nullptr;

    return newRoot;
}

TreeNode *BinaryTreeUpsideDown::upsideDownBinaryTree_Iterative(TreeNode *root) {
    TreeNode *curr = root;
    TreeNode *next = nullptr;
    TreeNode *prev = nullptr;
    TreeNode *prevRight = nullptr;

    while (curr) {
        next = curr->left;

        curr->left = prevRight;
        prevRight = curr->right;
        curr->right = prev;

        prev = curr;
        curr = next;
    }

    return prev;
}