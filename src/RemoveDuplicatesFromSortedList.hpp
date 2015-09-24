#ifndef REMOVE_DUPLICATES_FROM_SORTED_LIST_HPP_
#define REMOVE_DUPLICATES_FROM_SORTED_LIST_HPP_

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class RemoveDuplicatesFromSortedList {
public:
	ListNode* deleteDuplicates(ListNode* head);
};

#endif // REMOVE_DUPLICATES_FROM_SORTED_LIST_HPP_