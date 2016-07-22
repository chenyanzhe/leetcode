#include "DeleteNodeInALinkedList.hpp"

void DeleteNodeInALinkedList::deleteNode(ListNode *node) {
    node->val = node->next->val;
    node->next = node->next->next;
}