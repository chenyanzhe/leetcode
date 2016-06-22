#include "IntersectionOfTwoLinkedLists.hpp"

ListNode* IntersectionOfTwoLinkedLists::getIntersectionNode(ListNode* headA,
    ListNode* headB)
{
  int lengthA = getListLength(headA);
  int lengthB = getListLength(headB);

  if (lengthA == 0 || lengthB == 0)
    return nullptr;

  if (lengthA < lengthB) {
    for (int i = 0; i < lengthB - lengthA; i++)
      headB = headB->next;
  } else if (lengthA > lengthB) {
    for (int i = 0; i < lengthA - lengthB; i++)
      headA = headA->next;
  }

  while (headA != nullptr && headA != headB) {
    headA = headA->next;
    headB = headB->next;
  }

  return headA;
}

int IntersectionOfTwoLinkedLists::getListLength(ListNode* head)
{
  int length = 0;

  while (head != nullptr) {
    head = head->next;
    length++;
  }

  return length;
}
