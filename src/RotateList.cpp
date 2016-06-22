#include "RotateList.hpp"

ListNode* RotateList::rotateRight(ListNode* head, int k)
{
  return rotateRight_Cycle(head, k);
}

ListNode* RotateList::rotateRight_Cycle(ListNode* head, int k)
{
  if (head == nullptr)
    return head;

  int len = 1;
  ListNode* tail = head;

  while (tail->next) {
    tail = tail->next;
    len++;
  }

  // circle the list
  tail->next = head;
  ListNode* newHead = head;
  k %= len;

  for (int i = 0; i < len - k % len; i++)
    tail = tail->next;

  newHead = tail->next;
  tail->next = nullptr;
  return newHead;
}

ListNode* RotateList::rotateRight_TwoPointers(ListNode* head, int k)
{
  if (head == nullptr || head->next == nullptr)
    return head;

  ListNode dummy(0);
  dummy.next = head;
  ListNode* fast = &dummy;
  ListNode* slow = &dummy;
  int len = 0;

  while (fast->next) {
    fast = fast->next;
    len++;
  }

  for (int i = len - k % len; i > 0; i--)
    slow = slow->next;

  fast->next = dummy.next;
  dummy.next = slow->next;
  slow->next = nullptr;
  return dummy.next;
}
