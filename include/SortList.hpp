#ifndef SORT_LIST_HPP_
#define SORT_LIST_HPP_

#include "ListNode.hpp"

class SortList {
public:
    ListNode *sortList(ListNode *head);

private:
    ListNode *merge(ListNode *a, ListNode *b);
};

#endif // SORT_LIST_HPP_