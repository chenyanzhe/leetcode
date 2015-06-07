#include "RemoveNthNodeFromEndOfList.hpp"

ListNode* RemoveNthNodeFromEndOfList::removeNthFromEnd(ListNode* head, int n)
{
  if (head == nullptr) return nullptr;

  ListNode *p = head;
  ListNode *q = head;
  for (int i = 1; i < n; i++)
    q = q->next;

  ListNode *pp = nullptr;
  while (q->next != nullptr) {
    pp = p;
    p = p->next;
    q = q->next;
  }

  if (pp == nullptr)
    head = p->next;
  else
    pp->next = p->next;

  return head;
}
