#include "UniqueBinarySearchTreesII.hpp"

vector<TreeNode*> UniqueBinarySearchTreesII::generateTrees(int n)
{
  if (n == 0) {
    return vector<TreeNode*>();
  }

  vector<vector<vector<TreeNode*>>> dp(n + 2, vector<vector<TreeNode*>>(n + 2,
                                       vector<TreeNode*>()));

  for (int i = 1; i <= n + 1; i++) {
    dp[i][i].push_back(new TreeNode(i));
    dp[i][i - 1].push_back(NULL);
  }

  for (int l = 2; l <= n; l++) {
    for (int i = 1; i <= n + 1 - l; i++) {
      int j = i + l - 1;

      for (int k = i; k <= j; k++) {
        for (auto left : dp[i][k - 1]) {
          for (auto right : dp[k + 1][j]) {
            TreeNode* root = new TreeNode(k);
            root->left = left;
            root->right = right;
            dp[i][j].push_back(root);
          }
        }
      }
    }
  }

  return dp[1][n];
}

