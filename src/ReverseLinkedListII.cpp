#include "ReverseLinkedListII.hpp"

ListNode *ReverseLinkedListII::reverseBetween(ListNode *head, int m, int n) {
    ListNode *rprev = nullptr;
    ListNode *rhead = head;

    for (int i = 1; i < m; i++) {
        rprev = rhead;
        rhead = rhead->next;
    }

    ListNode *p1 = rhead, *p2 = rhead->next;

    for (int j = m; j <= n - 1; j++) {
        ListNode *tmp = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = tmp;
    }

    rhead->next = p2;

    if (rprev != nullptr)
        rprev->next = p1;
    else
        head = p1;

    return head;
}
