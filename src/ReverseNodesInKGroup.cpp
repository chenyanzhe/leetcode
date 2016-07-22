#include "ReverseNodesInKGroup.hpp"

ListNode *ReverseNodesInKGroup::reverseKGroup(ListNode *head, int k) {
    if (head == nullptr || head->next == nullptr || k < 2)
        return head;

    ListNode dummy(0);
    dummy.next = head;
    ListNode *prev = &dummy;
    ListNode *end = head;

    for (; end; end = prev->next) {
        for (int i = 1; i < k && end; i++)
            end = end->next;

        if (end == nullptr) {
            // do not have k elements
            break;
        }

        prev = reverse(prev, prev->next, end);
    }

    return dummy.next;
}

ListNode *ReverseNodesInKGroup::reverse(ListNode *prev, ListNode *begin,
                                        ListNode *end) {
    ListNode *end_next = end->next;
    ListNode *p = begin;
    ListNode *cur = p->next;
    ListNode *next = cur->next;

    for (; cur != end_next;
           p = cur, cur = next, next = next ? next->next : nullptr)
        cur->next = p;

    begin->next = end_next;
    prev->next = end;
    return begin;
}