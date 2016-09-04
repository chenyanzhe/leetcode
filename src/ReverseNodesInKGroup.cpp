#include "ReverseNodesInKGroup.hpp"

ListNode *ReverseNodesInKGroup::reverseKGroup(ListNode *head, int k) {
    if (k <= 1 || !head) return head;

    ListNode dummy(0);
    dummy.next = head;

    ListNode *prev = &dummy;
    while (prev) {
        // check there is k nodes after p
        ListNode *end = prev;
        for (int i = 0; i < k; i++) {
            end = end->next;
            if (!end) return dummy.next;
        }

        // reverse k nodes
        ListNode *endnext = end->next;
        ListNode *begin = prev->next;

        ListNode *a = begin;
        ListNode *b = a->next;
        while (a != end) {
            ListNode *bnext = b->next;
            b->next = a;
            a = b;
            b = bnext;
        }

        prev->next = end;
        begin->next = endnext;

        prev = begin;
    }

    return dummy.next;
}
