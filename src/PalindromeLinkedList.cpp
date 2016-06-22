#include "PalindromeLinkedList.hpp"

bool PalindromeLinkedList::isPalindrome(ListNode* head)
{
  ListNode* p = head;
  int len = 0;

  while (p != nullptr) {
    len++;
    p = p->next;
  }

  if (len == 0 || len == 1)
    return true;

  if (len == 2)
    return head->val == head->next->val;

  ListNode* prev = nullptr, *l, *r;

  if (len % 2 == 1) {
    p = head;

    for (int i = 0; i <= len / 2; i++) {
      ListNode* next = p->next;
      p->next = prev;
      prev = p;
      p = next;
    }

    l = prev->next;
    r = p;

    while (l != nullptr) {
      if (l->val != r->val)
        return false;

      l = l->next;
      r = r->next;
    }

    return true;
  } else {
    p = head;

    for (int i = 0; i < len / 2; i++) {
      ListNode* next = p->next;
      p->next = prev;
      prev = p;
      p = next;
    }

    ListNode* l = prev;
    ListNode* r = p;

    while (l != nullptr) {
      if (l->val != r->val)
        return false;

      l = l->next;
      r = r->next;
    }

    return true;
  }
}