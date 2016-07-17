#include "BinaryTreeRightSideView.hpp"

#include <queue>
using namespace std;

vector<int> BinaryTreeRightSideView::rightSideView(TreeNode* root)
{
  vector<int> ret;
  rightSideViewPreOrderTraversal(root, 1, ret);
  return ret;
}

vector<int> BinaryTreeRightSideView::rightSideViewLevelOrderTraversal(
  TreeNode* root)
{
  vector<int> ret;
  queue<TreeNode*> q;

  if (root != nullptr)
    q.push(root);

  while (!q.empty()) {
    int n = q.size();

    for (int i = 0; i < n; i++) {
      TreeNode* node = q.front();
      q.pop();

      if (node->left != nullptr)
        q.push(node->left);

      if (node->right != nullptr)
        q.push(node->right);

      if (i == n - 1)
        ret.push_back(node->val);
    }
  }

  return ret;
}

void BinaryTreeRightSideView::rightSideViewPreOrderTraversal(TreeNode* root,
    int level, vector<int>& res)
{
  if (root == nullptr)
    return;

  if (res.size() < level)
    res.push_back(root->val);

  rightSideViewPreOrderTraversal(root->right, level + 1, res);
  rightSideViewPreOrderTraversal(root->left, level + 1, res);
}
