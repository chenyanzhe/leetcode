#include "MergeTwoSortedLists.hpp"

ListNode* Solution::mergeTwoLists(ListNode* l1, ListNode* l2)
{
  ListNode *l = nullptr;
  ListNode *i = nullptr;
  ListNode *i1 = l1;
  ListNode *i2 = l2;

  while (i1 != nullptr && i2 != nullptr) {
    if (i1->val < i2->val) {
      if (l == nullptr)
        l = i1;
      else
        i->next = i1;
      i = i1;
      i1 = i1->next;
    } else {
      if (l == nullptr)
        l = i2;
      else
        i->next = i2;
      i = i2;
      i2 = i2->next;
    }
  }

  if (l == nullptr)
    l = (i1 != nullptr) ? i1 : i2;
  else
    i->next = (i1 != nullptr) ? i1 : i2;

  return l;
}
