#include "UniqueBinarySearchTreesII.hpp"

vector<TreeNode*> UniqueBinarySearchTreesII::generateTrees(int n)
{
  vector<vector<TreeNode*>> dp(n + 1);
  dp[0].push_back(nullptr);

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      for (auto l : dp[j - 1]) {
        for (auto r : dp[i - j]) {
          TreeNode* root = new TreeNode(j);
          // FIXME:
          // No need to clone left subtree
          // Tradeoff for correctly freeing all the trees
          root->left = clone(l, 0);
          root->right = clone(r, j);
          dp[i].push_back(root);
        }
      }
    }
  }

  return dp[n];
}

TreeNode* UniqueBinarySearchTreesII::clone(TreeNode* root, int offset)
{
  TreeNode* nroot = nullptr;

  if (root != nullptr) {
    nroot = new TreeNode(root->val + offset);
    nroot->left = clone(root->left, offset);
    nroot->right = clone(root->right, offset);
  }

  return nroot;
}
