#include "IntersectionOfTwoLinkedLists.hpp"

ListNode *IntersectionOfTwoLinkedLists::getIntersectionNode(ListNode *headA, ListNode *headB) {
    int lenA = 0, lenB = 0;
    ListNode *head;

    head = headA;
    while (head) {
        lenA++;
        head = head->next;
    }

    head = headB;
    while (head) {
        lenB++;
        head = head->next;
    }

    if (lenA == 0 || lenB == 0)
        return nullptr;

    if (lenA < lenB) {
        for (int i = 0; i < lenB - lenA; i++)
            headB = headB->next;
    } else {
        for (int i = 0; i < lenA - lenB; i++)
            headA = headA->next;
    }

    while (headA && headA != headB) {
        headA = headA->next;
        headB = headB->next;
    }

    return headA;
}
