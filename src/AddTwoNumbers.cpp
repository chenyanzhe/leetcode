#include "AddTwoNumbers.hpp"

ListNode *AddTwoNumbers::addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode dummyNode(0);
    ListNode *tail = &dummyNode;
    int carry = 0;
    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }
        carry = sum / 10;
        sum = sum % 10;
        tail->next = new ListNode(sum);
        tail = tail->next;
    }
    return dummyNode.next;
}
