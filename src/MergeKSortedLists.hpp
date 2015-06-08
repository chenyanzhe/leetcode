#ifndef MERGE_K_SORTED_LISTS_HPP_
#define MERGE_K_SORTED_LISTS_HPP_

#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class MergeKSortedLists {
public:
  ListNode* mergeKLists(vector<ListNode*>& lists);
};

#endif // MERGE_K_SORTED_LISTS_HPP_
