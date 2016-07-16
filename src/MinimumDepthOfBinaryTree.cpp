#include "MinimumDepthOfBinaryTree.hpp"

#include <queue>
using namespace std;

int MinimumDepthOfBinaryTree::minDepth(TreeNode* root)
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

      if (node->left == nullptr && node->right == nullptr)
        return depth;

      if (node->left != nullptr)
        q.push(node->left);

      if (node->right != nullptr)
        q.push(node->right);
    }
  }

  return depth;
}
