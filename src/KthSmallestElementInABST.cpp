#include "KthSmallestElementInABST.hpp"

int KthSmallestElementInABST::kthSmallest(TreeNode* root, int k)
{
  cnt = 0;
  result = 0;
  inOrderSearch(root, k);
  return result;
}

void KthSmallestElementInABST::inOrderSearch(TreeNode* root, int k)
{
  if (root == NULL) {
    return;
  }

  inOrderSearch(root->left, k);
  cnt++;

  if (cnt == k) {
    result = root->val;
  }

  inOrderSearch(root->right, k);
}
