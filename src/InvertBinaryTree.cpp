#include "InvertBinaryTree.hpp"

#include <stack>
#include <utility>
using namespace std;

TreeNode* InvertBinaryTree::invertTree(TreeNode* root)
{
  return invertTreeStack(root);
}

TreeNode* InvertBinaryTree::invertTreeRecursive(TreeNode* root)
{
  if (root == nullptr)
    return nullptr;

  swap(root->left, root->right);
  invertTree(root->left);
  invertTree(root->right);
  return root;
}

TreeNode* InvertBinaryTree::invertTreeStack(TreeNode* root)
{
  stack<TreeNode*> s;

  if (root != nullptr)
    s.push(root);

  while (!s.empty()) {
    TreeNode* node = s.top();
    s.pop();
    swap(node->left, node->right);

    if (node->left != nullptr)
      s.push(node->left);

    if (node->right != nullptr)
      s.push(node->right);
  }

  return root;
}
