#include "AddTwoNumbers.hpp"

ListNode* AddTwoNumbers::addTwoNumbers(ListNode* l1, ListNode* l2)
{
  ListNode* item = nullptr;
  ListNode* l3 = nullptr;
  ListNode* tail = nullptr;
  ListNode* p1 = l1;
  ListNode* p2 = l2;
  int carry = 0;

  while (p1 != nullptr && p2 != nullptr) {
    int v = p1->val + p2->val + carry;
    carry = v / 10;
    item = new ListNode(v % 10);

    if (l3 == nullptr) {
      l3 = item;
    } else {
      tail->next = item;
    }

    tail = item;
    p1 = p1->next;
    p2 = p2->next;
  }

  while (p1 != nullptr) {
    int v = p1->val + carry;
    carry = v / 10;
    item = new ListNode(v % 10);

    if (l3 == nullptr) {
      l3 = item;
    } else {
      tail->next = item;
    }

    tail = item;
    p1 = p1->next;
  }

  while (p2 != nullptr) {
    int v = p2->val + carry;
    carry = v / 10;
    item = new ListNode(v % 10);

    if (l3 == nullptr) {
      l3 = item;
    } else {
      tail->next = item;
    }

    tail = item;
    p2 = p2->next;
  }

  if (carry != 0) {
    item = new ListNode(carry);
    tail->next = item;
  }

  return l3;
}
