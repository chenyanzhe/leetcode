#include "SortList.hpp"

ListNode *SortList::sortList(ListNode *head) {
    if (head == nullptr || head->next == nullptr) return head;

    ListNode *slow = head;
    ListNode *fast = head->next->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = slow->next;
    slow->next = nullptr;
    return merge(sortList(head), sortList(fast));
}

ListNode *SortList::merge(ListNode *a, ListNode *b) {
    ListNode dummy(0);
    ListNode *tail = &dummy;
    while (a && b) {
        if (a->val < b->val) {
            tail->next = a;
            tail = a;
            a = a->next;
        } else {
            tail->next = b;
            tail = b;
            b = b->next;
        }
    }
    tail->next = a ? a : b;
    return dummy.next;
}