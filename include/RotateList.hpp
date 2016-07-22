#ifndef ROTATE_LIST_HPP_
#define ROTATE_LIST_HPP_

#include "ListNode.hpp"

class RotateList {
public:
    ListNode *rotateRight(ListNode *head, int k);

private:
    ListNode *rotateRight_Cycle(ListNode *head, int k);

    ListNode *rotateRight_TwoPointers(ListNode *head, int k);
};

#endif // ROTATE_LIST_HPP_
