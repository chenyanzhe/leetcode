#include "ConvertSortedArrayToBinarySearchTree.hpp"

TreeNode* ConvertSortedArrayToBinarySearchTree::sortedArrayToBST(
  vector<int>& nums)
{
  return sortedArrayTOBST(nums, 0, nums.size() - 1);
}

TreeNode* ConvertSortedArrayToBinarySearchTree::sortedArrayTOBST(
  vector<int>& nums, int begin, int end)
{
  if (begin > end) {
    return nullptr;
  }

  int mid = (begin + end) / 2;
  TreeNode* root = new TreeNode(nums[mid]);

  if (begin == end) {
    return root;
  }

  root->left = sortedArrayTOBST(nums, begin, mid - 1);
  root->right = sortedArrayTOBST(nums, mid + 1, end);
  return root;
}
