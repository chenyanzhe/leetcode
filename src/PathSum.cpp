#include "PathSum.hpp"

bool PathSum::hasPathSum(TreeNode* root, int sum)
{
  if (root == nullptr) {
    return false;
  }

  if (root->val == sum && root->left == nullptr && root->right == nullptr) {
    return true;
  }

  return hasPathSum(root->left, sum - root->val) ||
         hasPathSum(root->right, sum - root->val);
}
