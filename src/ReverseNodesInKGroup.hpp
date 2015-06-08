#ifndef REVERSE_NODES_IN_K_GROUP_HPP_
#define REVERSE_NODES_IN_K_GROUP_HPP_

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class ReverseNodesInKGroup {
public:
  ListNode* reverseKGroup(ListNode* head, int k);
};

#endif // REVERSE_NODES_IN_K_GROUP_HPP_
