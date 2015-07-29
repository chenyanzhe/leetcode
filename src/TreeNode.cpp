#include "TreeNode.hpp"

#include <queue>
using namespace std;

static void tree_serialize_helper(TreeNode *p, string &ans)
{
  if (p == nullptr)
    ans += "# ";
  else {
    ans += to_string(p->val) + " ";
    tree_serialize_helper(p->left, ans);
    tree_serialize_helper(p->right, ans);
  }
}

string tree_serialize(TreeNode* root) {
  string ret;
  tree_serialize_helper(root, ret);
  return ret;
}

void tree_free(TreeNode *root) {
  TreeNode *p = root;
  if (p == nullptr)
    return;

  queue<TreeNode *> *q = new queue<TreeNode *>();
  q->push(p);

  while (!q->empty()) {
    p = q->front();
    q->pop();
    if (p->left != nullptr)
      q->push(p->left);
    if (p->right != nullptr)
      q->push(p->right);
    delete p;
  }
  delete q;
}
