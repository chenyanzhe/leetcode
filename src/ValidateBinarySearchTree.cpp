#include "ValidateBinarySearchTree.hpp"

bool ValidateBinarySearchTree::isValidBST(TreeNode* root)
{
  if (root == nullptr)
    return true;

  if (root->left == nullptr && root->right == nullptr)
    return true;

  if (root->left == nullptr)
    return isValidBST(root->right) && root->val < minNodeVal(root->right);

  if (root->right == nullptr)
    return isValidBST(root->left) && root->val > maxNodeVal(root->left);

  return isValidBST(root->left) && root->val > maxNodeVal(root->left)
         && isValidBST(root->right) && root->val < minNodeVal(root->right);
}

// NOTE: This function assumes root is not null.
int ValidateBinarySearchTree::minNodeVal(TreeNode* root)
{
  while (root->left != nullptr)
    root = root->left;

  return root->val;
}

// NOTE: This function assumes root is not null.
int ValidateBinarySearchTree::maxNodeVal(TreeNode* root)
{
  while (root->right != nullptr)
    root = root->right;

  return root->val;
}
