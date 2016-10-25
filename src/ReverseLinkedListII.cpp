#include "ReverseLinkedListII.hpp"

ListNode *ReverseLinkedListII::reverseBetween(ListNode *head, int m, int n) {
    if (head == nullptr) return head;

    ListNode dummyHead(0);
    dummyHead.next = head;

    ListNode *prev = &dummyHead;
    for (int i = 0; i < m - 1; i++)
        prev = prev->next;

    ListNode *start = prev->next;
    ListNode *a = start;
    ListNode *b = a->next;

    for (int i = 0; i < n - m; i++) {
        ListNode *bnext = b->next;
        b->next = a;
        a = b;
        b = bnext;
    }

    prev->next = a;
    start->next = b;

    return dummyHead.next;
}
