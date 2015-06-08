#include "SwapNodesInPairs.hpp"

ListNode* SwapNodesInPairs::swapPairs(ListNode* head)
{
  if (head == nullptr || head->next == nullptr) return head;

  ListNode* prev = nullptr;
  ListNode* a = head;
  ListNode* b = head->next;
  ListNode* next = b->next;

  head = b; b->next = a; a->next = next;

  while (next != nullptr && next->next != nullptr) {
    prev = a;
    a = next;
    b = a->next;
    next = b->next;

    prev->next = b; b->next = a; a->next = next;
  }

  return head;
}
