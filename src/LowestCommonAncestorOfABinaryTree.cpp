#include "LowestCommonAncestorOfABinaryTree.hpp"

#include <stack>
#include <unordered_set>
#include <unordered_map>
using namespace std;

TreeNode* LowestCommonAncestorOfABinaryTree::lowestCommonAncestor(
  TreeNode* root, TreeNode* p, TreeNode* q)
{
  return lowestCommonAncestorRecursive(root, p, q);
}

TreeNode* LowestCommonAncestorOfABinaryTree::lowestCommonAncestorRecursive(
  TreeNode* root, TreeNode* p, TreeNode* q)
{
  if (root == nullptr || root == p || root == q)
    return root;

  TreeNode* l = lowestCommonAncestor(root->left, p, q);
  TreeNode* r = lowestCommonAncestor(root->right, p, q);

  if (l && r)
    return root;

  return l ? l : r;
}

TreeNode* LowestCommonAncestorOfABinaryTree::lowestCommonAncestorIterative(
  TreeNode* root, TreeNode* p, TreeNode* q)
{
  unordered_map<TreeNode*, TreeNode*> parent;
  stack<TreeNode*> s;
  parent[root] = nullptr;
  s.push(root);

  while (!parent.count(p) || !parent.count(q)) {
    TreeNode* node = s.top();
    s.pop();

    if (node->left != nullptr) {
      parent[node->left] = node;
      s.push(node->left);
    }

    if (node->right != nullptr) {
      parent[node->right] = node;
      s.push(node->right);
    }
  }

  unordered_set<TreeNode*> ancestors;

  while (p != nullptr) {
    ancestors.insert(p);
    p = parent[p];
  }

  while (!ancestors.count(q))
    q = parent[q];

  return q;
}
