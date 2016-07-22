#include "RemoveDuplicatesFromSortedListII.hpp"

ListNode *RemoveDuplicatesFromSortedListII::deleteDuplicates(ListNode *head) {
    ListNode *first;
    ListNode *second;

    while (head != nullptr && head->next != nullptr) {
        ListNode *first = head;
        ListNode *second = head->next;

        while (second != nullptr && first->val == second->val) {
            first = second;
            second = second->next;
        }

        if (second == nullptr)
            head = nullptr;
        else if (head != first)
            head = second;
        else
            break;
    }

    ListNode *prevItem = head;

    while (prevItem != nullptr) {
        ListNode *nextItem = prevItem->next;

        while (nextItem != nullptr && nextItem->next != nullptr) {
            first = nextItem;
            second = nextItem->next;

            while (second != nullptr && first->val == second->val) {
                first = second;
                second = second->next;
            }

            if (second == nullptr)
                nextItem = nullptr;
            else if (nextItem != first)
                nextItem = second;
            else
                break;
        }

        prevItem->next = nextItem;
        prevItem = nextItem;
    }

    return head;
}
