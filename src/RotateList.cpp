#include "RotateList.hpp"

ListNode* RotateList::rotateRight(ListNode* head, int k)
{
  int sz = nodeNums(head);

  if (sz == 0) {
    return head;
  }

  k = k % sz;

  if (k == 0) {
    return head;
  }

  ListNode* oldTail = getNode(head, sz);
  ListNode* newTail = getNode(head, sz - k);
  ListNode* newHead = newTail->next;
  newTail->next = nullptr;
  oldTail->next = head;
  head = newHead;
  return head;
}

int RotateList::nodeNums(ListNode* head)
{
  int nums = 0;

  while (head != nullptr) {
    nums++;
    head = head->next;
  }

  return nums;
}

ListNode* RotateList::getNode(ListNode* head, int i)
{
  while (i > 1 && head != nullptr) {
    head = head->next;
    i--;
  }

  return head;
}
