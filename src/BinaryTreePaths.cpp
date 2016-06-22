#include "BinaryTreePaths.hpp"

vector<string> BinaryTreePaths::binaryTreePaths(TreeNode* root)
{
  vector<string> ret;
  dfs(root, "", ret);
  return ret;
}

void BinaryTreePaths::dfs(TreeNode* root, string path, vector<string>& ret)
{
  if (root == nullptr)
    return;

  if (path.empty())
    path = to_string(root->val);
  else
    path += "->" + to_string(root->val);

  if (root->left || root->right) {
    dfs(root->left, path, ret);
    dfs(root->right, path, ret);
  } else
    ret.push_back(path);
}