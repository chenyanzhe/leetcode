#include "FlattenBinaryTreeToLinkedList.hpp"

void FlattenBinaryTreeToLinkedList::flatten(TreeNode* root)
{
  if (root == nullptr)
    return;

  // flatten left subtree
  if (root->left != nullptr)
    flatten(root->left);

  // flatten right subtree
  if (root->right != nullptr)
    flatten(root->right);

  if (root->left != nullptr) {
    // make left subtree as the right node of root
    // and empty root's left node
    TreeNode* rt = root->right;
    root->right = root->left;
    root->left = nullptr;
    // 1. find the tail node of the first list (head at root)
    TreeNode* tail = root->right;

    while (tail->right != nullptr)
      tail = tail->right;

    // 2. link two lists (head at root and rt) together
    tail->right = rt;
  }
}
