#ifndef REMOVE_NTH_NODE_FROM_END_OF_LIST_HPP_
#define REMOVE_NTH_NODE_FROM_END_OF_LIST_HPP_

// Definition for singly-linked list
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class RemoveNthNodeFromEndOfList {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n);
};

#endif // REMOVE_NTH_NODE_FROM_END_OF_LIST_HPP_
