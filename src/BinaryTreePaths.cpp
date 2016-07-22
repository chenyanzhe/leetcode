#include "BinaryTreePaths.hpp"

vector<string> BinaryTreePaths::binaryTreePaths(TreeNode *root) {
    vector<string> ret;

    if (root != nullptr)
        dfs(root, "", ret);

    return ret;
}

void BinaryTreePaths::dfs(TreeNode *root, string path, vector<string> &ret) {
    string val = to_string(root->val);

    if (root->left == nullptr && root->right == nullptr)
        ret.push_back(path + val);

    if (root->left != nullptr)
        dfs(root->left, path + val + "->", ret);

    if (root->right != nullptr)
        dfs(root->right, path + val + "->", ret);
}
