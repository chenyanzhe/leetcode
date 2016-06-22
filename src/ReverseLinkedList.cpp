#include "ReverseLinkedList.hpp"

ListNode* ReverseLinkedList::reverseList(ListNode* head)
{
  if (head == nullptr)
    return head;

  ListNode* prev = nullptr;
  ListNode* now = head;
  ListNode* next = now->next;

  while (next != nullptr) {
    now->next = prev;
    prev = now;
    now = next;
    next = now->next;
  }

  now->next = prev;
  return now;
}
