#include "BinaryTreePostorderTraversal.hpp"

#include <stack>
using namespace std;

vector<int> BinaryTreePostorderTraversal::postorderTraversal(TreeNode* root)
{
  return postorderTraversal_Stack(root);
}

vector<int> BinaryTreePostorderTraversal::postorderTraversal_Stack(
  TreeNode* root)
{
  vector<int> ret;
  stack<TreeNode*> s1;
  stack<TreeNode*> s2;

  if (root != nullptr) s1.push(root);

  while (!s1.empty()) {
    TreeNode* current = s1.top();
    s1.pop();
    s2.push(current);

    if (current->left != nullptr)
      s1.push(current->left);

    if (current->right != nullptr)
      s1.push(current->right);
  }

  while (!s2.empty()) {
    TreeNode* current = s2.top();
    s2.pop();
    ret.push_back(current->val);
  }

  return ret;
}

