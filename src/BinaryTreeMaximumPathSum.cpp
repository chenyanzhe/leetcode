#include "BinaryTreeMaximumPathSum.hpp"

#include <climits>
using namespace std;

int BinaryTreeMaximumPathSum::maxPathSum(TreeNode* root)
{
  max_sum = INT_MIN;
  dfs(root);
  return max_sum;
}

int BinaryTreeMaximumPathSum::dfs(const TreeNode* root)
{
  if (root == nullptr) {
    return 0;
  }

  int l = dfs(root->left);
  int r = dfs(root->right);
  int sum = root->val;

  if (l > 0) {
    sum += l;
  }

  if (r > 0) {
    sum += r;
  }

  max_sum = max(max_sum, sum);
  return max(r, l) > 0 ? max(r, l) + root->val : root->val;
}
