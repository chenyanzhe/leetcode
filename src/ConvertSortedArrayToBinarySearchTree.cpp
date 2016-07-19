#include "ConvertSortedArrayToBinarySearchTree.hpp"

TreeNode* ConvertSortedArrayToBinarySearchTree::sortedArrayToBST(
  vector<int>& nums)
{
  return sortedArrayToBST(nums, 0, nums.size() - 1);
}

TreeNode* ConvertSortedArrayToBinarySearchTree::sortedArrayToBST(
  vector<int>& nums, int begin, int end)
{
  if (begin > end) return nullptr;

  int mid = (begin + end) / 2;
  TreeNode* root = new TreeNode(nums[mid]);
  root->left = sortedArrayToBST(nums, begin, mid - 1);
  root->right = sortedArrayToBST(nums, mid + 1, end);
  return root;
}
