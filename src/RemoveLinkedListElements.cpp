#include "RemoveLinkedListElements.hpp"

ListNode *RemoveLinkedListElements::removeElements(ListNode *head, int val) {
    ListNode dummy(0);
    dummy.next = head;

    ListNode *cur = &dummy;

    while (cur) {
        if (cur->next && cur->next->val == val) cur->next = cur->next->next;
        else cur = cur->next;
    }

    return dummy.next;
}
