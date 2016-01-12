#include "ConvertSortedListToBinarySearchTree.hpp"

TreeNode* ConvertSortedListToBinarySearchTree::sortedListToBST(ListNode* head)
{
  this->head = head;
  int len = list_len(head);
  return sortedListToBST(0, len - 1);
}

TreeNode* ConvertSortedListToBinarySearchTree::sortedListToBST(int start,
    int end)
{
  if (start > end) {
    return nullptr;
  }

  int mid = (start + end) / 2;
  TreeNode* left = sortedListToBST(start, mid - 1);
  TreeNode* root = new TreeNode(head->val);
  head = head->next;
  TreeNode* right = sortedListToBST(mid + 1, end);
  root->left = left;
  root->right = right;
  return root;
}
