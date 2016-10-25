
#include "OddEvenLinkedList.hpp"

ListNode *OddEvenLinkedList::oddEvenList(ListNode *head) {
    ListNode dummy1(0);
    ListNode *tail1 = &dummy1;
    ListNode dummy2(0);
    ListNode *tail2 = &dummy2;

    while (head && head->next) {
        tail1->next = head;
        tail1 = head;
        head = head->next;
        tail2->next = head;
        tail2 = head;
        head = head->next;
    }

    if (head) {
        tail1->next = head;
        tail1 = head;
    }
    tail1->next = dummy2.next;
    tail2->next = nullptr;

    return dummy1.next;
}
