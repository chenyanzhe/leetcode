#ifndef CONVERT_SORTED_LIST_TO_BINARY_SEARCH_TREE_HPP_
#define CONVERT_SORTED_LIST_TO_BINARY_SEARCH_TREE_HPP_

#include "TreeNode.hpp"
#include "ListNode.hpp"

class ConvertSortedListToBinarySearchTree {
public:
    TreeNode *sortedListToBST(ListNode *head);

private:
    TreeNode *helper(ListNode *start, ListNode *end);
};

#endif // CONVERT_SORTED_LIST_TO_BINARY_SEARCH_TREE_HPP_
