#include "SymmetricTree.hpp"

#include <queue>
using namespace std;

bool SymmetricTree::isSymmetric(TreeNode* root)
{
  // iterative version
  return isSymmetricIter(root);
  // recursive version
  // return root == nullptr || isSymmetricHelper(root->left, root->right);
}

bool SymmetricTree::isSymmetricHelper(TreeNode* l, TreeNode* r)
{
  if (l == nullptr || r == nullptr)
    return l == r;

  if (l->val != r->val)
    return false;

  return isSymmetricHelper(l->left, r->right) &&
         isSymmetricHelper(l->right, r->left);
}

bool SymmetricTree::isSymmetricIter(TreeNode* root)
{
  queue<TreeNode*> q;
  q.push(root);
  q.push(root);

  while (!q.empty()) {
    TreeNode* l = q.front();
    q.pop();
    TreeNode* r = q.front();
    q.pop();

    if (l == nullptr && r == nullptr)
      continue;

    if (l == nullptr || r == nullptr)
      return false;

    if (l->val != r->val)
      return false;

    q.push(l->left);
    q.push(r->right);
    q.push(l->right);
    q.push(r->left);
  }

  return true;
}
