#ifndef ROTATE_LIST_HPP_
#define ROTATE_LIST_HPP_

#include "ListNode.hpp"

class RotateList
{
public:
  ListNode* rotateRight(ListNode* head, int k);
private:
  int nodeNums(ListNode* head);
  ListNode* getNode(ListNode* head, int i);
};

#endif // ROTATE_LIST_HPP_
