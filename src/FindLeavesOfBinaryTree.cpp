#include "FindLeavesOfBinaryTree.hpp"

#include <unordered_set>
#include <algorithm>
#include <stack>

using namespace std;

vector<vector<int>> FindLeavesOfBinaryTree::findLeaves(TreeNode *root) {
    vector<vector<int>> ret;
    height(root, ret);
    return ret;
}

int FindLeavesOfBinaryTree::height(TreeNode *root, vector<vector<int>> &ret) {
    if (root == nullptr) return -1;
    int level = 1 + max(height(root->left, ret), height(root->right, ret));
    if (ret.size() < level + 1) ret.push_back(vector<int>(0));
    ret[level].push_back(root->val);
    return level;
}