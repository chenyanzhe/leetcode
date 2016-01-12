#include "ReverseNodesInKGroup.hpp"

ListNode* ReverseNodesInKGroup::reverseKGroup(ListNode* head, int k)
{
  if (head == nullptr || k == 1) {
    return head;
  }

  ListNode* prev = nullptr;
  ListNode* a = head;
  ListNode* b = a;

  for (int i = 1; i < k; i++) {
    b = b->next;

    if (b == nullptr) {
      return head;
    }
  }

  ListNode* next = b->next;
  head = b;
  ListNode* p = a;
  ListNode* q = p->next;

  while (p != b) {
    ListNode* t = q->next;
    q->next = p;
    p = q;
    q = t;
  }

  a->next = next;

  while (next != nullptr) {
    prev = a;
    a = next;
    b = a;

    for (int i = 1; i < k; i++) {
      b = b->next;

      if (b == nullptr) {
        return head;
      }
    }

    next = b->next;
    prev->next = b;
    p = a;
    q = p->next;

    while (p != b) {
      ListNode* t = q->next;
      q->next = p;
      p = q;
      q = t;
    }

    a->next = next;
  }

  return head;
}
