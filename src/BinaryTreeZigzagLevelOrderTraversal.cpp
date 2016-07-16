#include "BinaryTreeZigzagLevelOrderTraversal.hpp"

#include <queue>
using namespace std;

vector<vector<int>> BinaryTreeZigzagLevelOrderTraversal::zigzagLevelOrder(
                   TreeNode* root)
{
  vector<vector<int>> ret;
  queue<TreeNode*> q;
  bool reverse = false;

  if (root != nullptr) q.push(root);

  while (!q.empty()) {
    int n = q.size();
    vector<int> newlevel(n);

    for (int i = 0; i < n; i++) {
      TreeNode* current = q.front();
      q.pop();

      if (reverse)
        newlevel[n - i - 1] = current->val;
      else
        newlevel[i] = current->val;

      if (current->left != nullptr)
        q.push(current->left);

      if (current->right != nullptr)
        q.push(current->right);
    }

    ret.push_back(newlevel);
    reverse = !reverse;
  }

  return ret;
}
