
#include "ReorderList.hpp"

void ReorderList::reorderList(ListNode *head) {
    if (head == nullptr) return;

    ListNode *fast = head;
    ListNode *slow = head;
    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }

    ListNode *l1 = head;
    ListNode *l2 = slow->next;
    slow->next = nullptr;

    if (l2 == nullptr) return;

    ListNode *a = l2;
    ListNode *b = l2->next;
    while (b) {
        ListNode *bnext = b->next;
        b->next = a;
        a = b;
        b = bnext;
    }

    l2->next = nullptr;
    l2 = a;

    ListNode dummy(0);
    ListNode *tail = &dummy;

    while (l1 && l2) {
        tail->next = l1;
        l1 = l1->next;
        tail = tail->next;
        tail->next = l2;
        l2 = l2->next;
        tail = tail->next;
    }

    tail->next = l1 ? l1 : l2;
}
