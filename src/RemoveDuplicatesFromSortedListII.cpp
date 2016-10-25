#include "RemoveDuplicatesFromSortedListII.hpp"

ListNode *RemoveDuplicatesFromSortedListII::deleteDuplicates(ListNode *head) {
    if (head == nullptr) return head;

    ListNode dummyHead(0);
    dummyHead.next = head;

    ListNode *a = &dummyHead;
    ListNode *b = head;
    ListNode *c = head->next;

    bool dup = false;

    while (c) {
        if (b->val == c->val) {
            dup = true;
            c = c->next;
            if (c == nullptr) a->next = nullptr;
        } else {
            if (dup) {
                a->next = c;
                b = c;
                c = c->next;
                dup = false;
            } else {
                a = b;
                b = c;
                c = c->next;
            }
        }
    }

    return dummyHead.next;
}
