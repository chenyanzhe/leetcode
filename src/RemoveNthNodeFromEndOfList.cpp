#include "RemoveNthNodeFromEndOfList.hpp"

ListNode* RemoveNthNodeFromEndOfList::removeNthFromEnd(ListNode* head, int n)
{
  if (head == nullptr) {
    return nullptr;
  }

  ListNode dummyHead(0);
  dummyHead.next = head;
  ListNode* fast = &dummyHead;
  ListNode* slow = &dummyHead;

  while (n--) {
    fast = fast->next;
  }

  while (fast->next) {
    fast = fast->next;
    slow = slow->next;
  }

  slow->next = slow->next->next;
  return dummyHead.next;
}
