#ifndef CONVERT_SORTED_LIST_TO_BINARY_SEARCH_TREE_HPP_
#define CONVERT_SORTED_LIST_TO_BINARY_SEARCH_TREE_HPP_

#include "TreeNode.hpp"
#include "ListNode.hpp"

class ConvertSortedListToBinarySearchTree
{
private:
  ListNode* head;
public:
  TreeNode* sortedListToBST(ListNode* head);
private:
  TreeNode* sortedListToBST(int start, int end);
};

#endif // CONVERT_SORTED_LIST_TO_BINARY_SEARCH_TREE_HPP_
