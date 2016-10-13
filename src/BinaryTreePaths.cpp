#include "BinaryTreePaths.hpp"

vector<string> BinaryTreePaths::binaryTreePaths(TreeNode *root) {
    vector<string> ret;

    if (root != nullptr)
        dfs(root, to_string(root->val), ret);

    return ret;
}

void BinaryTreePaths::dfs(TreeNode *root, string path, vector<string> &ret) {
    if (root->left == nullptr && root->right == nullptr) {
        ret.push_back(path);
        return;
    }

    if (root->left)
        dfs(root->left, path + "->" + to_string(root->left->val), ret);

    if (root->right)
        dfs(root->right, path + "->" + to_string(root->right->val), ret);
}
