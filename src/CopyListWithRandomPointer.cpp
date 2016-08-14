#include "CopyListWithRandomPointer.hpp"

RandomListNode *CopyListWithRandomPointer::copyRandomList(RandomListNode *head) {
    duplicate(head);
    fixRandom(head);
    return unwind(head);
}

void CopyListWithRandomPointer::duplicate(RandomListNode *head) {
    RandomListNode *node = head;
    while (head) {
        RandomListNode *newItem = new RandomListNode(head->label);
        newItem->next = head->next;
        head->next = newItem;
        head = newItem->next;
    }
}

void CopyListWithRandomPointer::fixRandom(RandomListNode *head) {
    while (head) {
        if (head->random) {
            head->next->random = head->random->next;
        }
        head = head->next->next;
    }
}

RandomListNode *CopyListWithRandomPointer::unwind(RandomListNode *head) {
    if (head == nullptr) return nullptr;

    RandomListNode *tail = head;
    RandomListNode *head2 = head->next;
    RandomListNode *tail2 = head2;

    while (tail->next->next) {
        RandomListNode *nextTail = tail->next->next;
        tail->next = nextTail;
        tail = nextTail;

        RandomListNode *nextTail2 = tail2->next->next;
        tail2->next = nextTail2;
        tail2 = nextTail2;
    }

    tail->next = tail2->next = nullptr;

    return head2;
}