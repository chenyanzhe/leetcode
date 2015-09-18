#ifndef ADD_TWO_NUMBERS_HPP_
#define ADD_TWO_NUMBERS_HPP_

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class AddTwoNumbers {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
};

#endif // ADD_TWO_NUMBERS_HPP_
