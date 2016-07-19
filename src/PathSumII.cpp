#include "PathSumII.hpp"

vector<vector<int>> PathSumII::pathSum(TreeNode* root, int sum)
{
  vector<vector<int>> res;
  vector<int> path;
  pathSum(root, path, sum, res);
  return res;
}

void PathSumII::pathSum(TreeNode* root, vector<int>& path, int sum,
                        vector<vector<int>>& res)
{
  if (root == nullptr)
    return;

  path.push_back(root->val);

  if (root->val == sum && root->left == nullptr && root->right == nullptr)
    res.push_back(path);

  pathSum(root->left, path, sum - root->val, res);
  pathSum(root->right, path, sum - root->val, res);
  path.pop_back();
}
