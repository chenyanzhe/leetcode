#include "ListNode.hpp"

string list_serialize(ListNode *head) {
	string ret = "";
	while (head != nullptr) {
		ret += to_string(head->val) + " ";
		head = head->next;
	}
	return ret;
}
void list_free(ListNode *head) {
	while (head != nullptr) {
		ListNode *tmp = head;
	  	head = head->next;
	  	delete tmp;
	}
}