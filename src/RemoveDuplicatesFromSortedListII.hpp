#ifndef REMOVE_DUPLICATES_FROM_SORTED_LIST_II_HPP_
#define REMOVE_DUPLICATES_FROM_SORTED_LIST_II_HPP_

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class RemoveDuplicatesFromSortedListII {
public:
	ListNode* deleteDuplicates(ListNode* head);
private:
	ListNode* findDuplicates(ListNode* head);
};

#endif // REMOVE_DUPLICATES_FROM_SORTED_LIST_II_HPP_