#include "BalancedBinaryTree.hpp"

#include <algorithm>
#include <cstdlib>
using namespace std;

bool BalancedBinaryTree::isBalanced(TreeNode* root)
{
  if (root == nullptr)
    return true;

  int leftHeight = depth(root->left);
  int rightHeight = depth(root->right);

  if (leftHeight == -1 || rightHeight == -1)
    return false;

  return abs(leftHeight - rightHeight) <= 1;
}

int BalancedBinaryTree::depth(TreeNode* root)
{
  if (root == nullptr)
    return 0;

  int leftHeight = depth(root->left);
  int rightHeight = depth(root->right);

  if (leftHeight == -1 || rightHeight == -1)
    return -1;

  if (abs(leftHeight - rightHeight) > 1)
    return -1;

  return max(leftHeight, rightHeight) + 1;
}
