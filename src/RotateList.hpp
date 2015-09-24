#ifndef ROTATE_LIST_HPP_
#define ROTATE_LIST_HPP_

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class RotateList {
public:
	ListNode* rotateRight(ListNode* head, int k);
private:
	int nodeNums(ListNode* head);
	ListNode* getNode(ListNode* head, int i);
};

#endif // ROTATE_LIST_HPP_