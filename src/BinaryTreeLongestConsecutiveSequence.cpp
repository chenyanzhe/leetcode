#include "BinaryTreeLongestConsecutiveSequence.hpp"

int BinaryTreeLongestConsecutiveSequence::longestConsecutive(TreeNode *root) {
    int ret = 0;
    if (root == nullptr) return 0;
    dfs(root, 0, root->val, ret);
    return ret;
}

void BinaryTreeLongestConsecutiveSequence::dfs(TreeNode *root, int cur, int target, int &global) {
    if (root == nullptr) return;
    if (root->val == target) cur++;
    else cur = 1;
    global = max(cur, global);
    dfs(root->left, cur, root->val + 1, global);
    dfs(root->right, cur, root->val + 1, global);
}