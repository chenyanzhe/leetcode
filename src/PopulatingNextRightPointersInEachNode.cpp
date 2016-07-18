#include "PopulatingNextRightPointersInEachNode.hpp"

void PopulatingNextRightPointersInEachNode::connect(TreeLinkNode* root)
{
  if (root == nullptr)
    return;

  TreeLinkNode* leftMost = root;

  while (leftMost != nullptr && leftMost->left != nullptr) {
    TreeLinkNode* current = leftMost;

    while (current != nullptr) {
      current->left->next = current->right;
      current->right->next = current->next ? current->next->left : nullptr;
      current = current->next;
    }

    leftMost = leftMost->left;
  }
}
