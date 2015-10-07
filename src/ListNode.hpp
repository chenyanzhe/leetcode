#ifndef LIST_NODE_HPP_
#define LIST_NODE_HPP_

#include <string>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

string list_serialize(ListNode *head);
void list_free(ListNode *head);

#endif // LIST_NODE_HPP_