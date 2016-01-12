#include "SumRootToLeafNumbers.hpp"

int SumRootToLeafNumbers::sumNumbers(TreeNode* root)
{
  vector<TreeNode*> path;
  vector<vector<int>> result;
  int ret = 0;

  if (root == nullptr) {
    return 0;
  }

  dfs(path, result, root);

  for (const auto& num : result) {
    ret += getNumberVal(num);
  }

  return ret;
}

void SumRootToLeafNumbers::dfs(vector<TreeNode*>& path,
                               vector<vector<int>>& result, TreeNode* start)
{
  if (start->left == nullptr && start->right == nullptr) {
    vector<int> r;

    for (auto n : path) {
      r.push_back(n->val);
    }

    r.push_back(start->val);
    result.push_back(r);
    return;
  }

  if (start->left != nullptr) {
    path.push_back(start);
    dfs(path, result, start->left);
    path.pop_back();
  }

  if (start->right != nullptr) {
    path.push_back(start);
    dfs(path, result, start->right);
    path.pop_back();
  }
}

int SumRootToLeafNumbers::getNumberVal(const vector<int>& num)
{
  int result = 0;

  for (auto d : num) {
    result = result * 10 + d;
  }

  return result;
}
