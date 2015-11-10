#ifndef INTERSECTION_OF_TWO_LINKED_LISTS_HPP_
#define INTERSECTION_OF_TWO_LINKED_LISTS_HPP_

#include "ListNode.hpp"

class IntersectionOfTwoLinkedLists {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);
private:
    int getListLength(ListNode *head);
};

#endif // INTERSECTION_OF_TWO_LINKED_LISTS_HPP_