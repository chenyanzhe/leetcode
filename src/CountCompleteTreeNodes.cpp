#include "CountCompleteTreeNodes.hpp"

int CountCompleteTreeNodes::countNodes(TreeNode* root)
{
  if (root == nullptr) {
    return 0;
  }

  if (root->left == nullptr) {
    return 1;
  }

  if (root->right == nullptr) {
    return 2;
  }

  TreeNode* ln = root;
  int ld = 0;

  while (ln != nullptr) {
    ld++;
    ln = ln->left;
  }

  TreeNode* rn = root;
  int rd = 0;

  while (rn != nullptr) {
    rd++;
    rn = rn->right;
  }

  if (ld == rd) {
    return (1 << ld) - 1;
  } else {
    return 1 + countNodes(root->left) + countNodes(root->right);
  }
}
