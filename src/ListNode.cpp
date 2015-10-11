#include "ListNode.hpp"

int list_len(ListNode *head) {
	int len = 0;
	while (head != nullptr) {
		len++;
		head = head->next;
	}
	return len;
}

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