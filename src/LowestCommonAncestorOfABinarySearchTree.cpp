#include "LowestCommonAncestorOfABinarySearchTree.hpp"

TreeNode* LowestCommonAncestorOfABinarySearchTree::lowestCommonAncestor(
  TreeNode* root, TreeNode* p, TreeNode* q)
{
  if (root == nullptr || p == nullptr || q == nullptr) {
    return nullptr;
  }

  if (p->val > q->val) {
    return lowestCommonAncestor(root, q, p);
  }

  if (p->val == q->val) {
    return p;
  }

  if (root->val == p->val) {
    return p;
  }

  if (root->val == q->val) {
    return q;
  }

  if (p->val < root->val && root->val < q->val) {
    return root;
  }

  if (q->val < root->val) {
    return lowestCommonAncestor(root->left, p, q);
  } else {
    return lowestCommonAncestor(root->right, p, q);
  }
}
