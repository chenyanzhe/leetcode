#include "MaximumDepthOfBinaryTree.hpp"

#include <algorithm>
#include <queue>
using namespace std;

int MaximumDepthOfBinaryTree::maxDepth(TreeNode* root)
{
  return maxDepthIterative(root);
}

int MaximumDepthOfBinaryTree::maxDepthRecursive(TreeNode* root)
{
  if (root == nullptr)
    return 0;

  int left = maxDepth(root->left);
  int right = maxDepth(root->right);
  return max(left, right) + 1;
}

int MaximumDepthOfBinaryTree::maxDepthIterative(TreeNode* root)
{
  queue<TreeNode*> q;
  int depth = 0;

  if (root != nullptr) q.push(root);

  while (!q.empty()) {
    depth++;
    int n = q.size();

    for (int i = 0; i < n; i++) {
      TreeNode* node = q.front();
      q.pop();

      if (node->left != nullptr)
        q.push(node->left);

      if (node->right != nullptr)
        q.push(node->right);
    }
  }

  return depth;
}
