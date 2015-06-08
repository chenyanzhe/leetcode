#ifndef SWAP_NODES_IN_PAIRS_HPP_
#define SWAP_NODES_IN_PAIRS_HPP_

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class SwapNodesInPairs {
public:
  ListNode* swapPairs(ListNode* head);
};

#endif // SWAP_NODES_IN_PAIRS_HPP_
