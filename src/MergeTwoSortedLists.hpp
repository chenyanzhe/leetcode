#ifndef MERGE_TWO_SORTED_LISTS_HPP_
#define MERGE_TWO_SORTED_LISTS_HPP_

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class MergeTwoSortedLists {
public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
};

#endif // MERGE_TWO_SORTED_LISTS_HPP_
