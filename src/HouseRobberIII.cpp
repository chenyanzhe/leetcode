#include "HouseRobberIII.hpp"

using namespace std;

int HouseRobberIII::rob(TreeNode *root) {
    vector<int> ret = robGreedy(root);
    return max(ret[0], ret[1]);
    /*
      unordered_map<TreeNode*, int> mem;
      return robMem(root, mem);
    */
}

// Recursive + Memoization
int HouseRobberIII::robMem(TreeNode *root, unordered_map<TreeNode *, int> &mem) {
    if (root == nullptr)
        return 0;

    if (mem.find(root) != mem.end())
        return mem[root];

    int val = root->val;

    if (root->left)
        val += robMem(root->left->left, mem) + robMem(root->left->right, mem);

    if (root->right)
        val += robMem(root->right->left, mem) + robMem(root->right->right, mem);

    int ret = max(val, robMem(root->left, mem) + robMem(root->right, mem));
    mem[root] = ret;
    return ret;
}

vector<int> HouseRobberIII::robGreedy(TreeNode *root) {
    if (root == nullptr)
        return vector<int>(2, 0);

    // first element: root is not robbed
    // second element: root is robbed
    vector<int> ret(2, 0);
    vector<int> left = robGreedy(root->left);
    vector<int> right = robGreedy(root->right);
    // if root is not robbed, feel free to rob its subtree
    ret[0] = max(left[0], left[1]) + max(right[0], right[1]);
    // if root is robbed, subtree's root cannot be robbed
    ret[1] = root->val + left[0] + right[0];
    return ret;
}
