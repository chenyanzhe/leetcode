#include "RemoveLinkedListElements.hpp"

ListNode *RemoveLinkedListElements::removeElements(ListNode *head, int val) {
    while (head != nullptr && head->val == val)
        head = head->next;

    if (head == nullptr)
        return nullptr;

    ListNode *p = head;
    ListNode *q = head->next;

    while (q != nullptr) {
        if (q->val == val) {
            p->next = q->next;
            q = q->next;
        } else {
            p = q;
            q = q->next;
        }
    }

    return head;
}
