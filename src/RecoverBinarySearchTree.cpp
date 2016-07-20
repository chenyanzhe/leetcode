#include "RecoverBinarySearchTree.hpp"

#include <algorithm>
using namespace std;

void RecoverBinarySearchTree::recoverTree(TreeNode* root)
{
  TreeNode* prev = nullptr, *first = nullptr, *second = nullptr;
  findSegments(root, prev, first, second);
  swap(first->val, second->val);
}

void RecoverBinarySearchTree::findSegments(TreeNode* root, TreeNode*& prev,
    TreeNode*& first, TreeNode*& second)
{
  if (root == nullptr)
    return;

  findSegments(root->left, prev, first, second);

  if (prev != nullptr && prev->val > root->val) {
    if (first == nullptr)
      first = prev;

    second = root;
  }

  prev = root;
  findSegments(root->right, prev, first, second);
}
